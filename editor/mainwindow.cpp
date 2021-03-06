#include "mainwindow.h"

#include <QDebug>
#include <QtWidgets>

#include "aboutdialog.h"

#include "../audio/audio.h"
#include "../audio/audioproc.h"
#include "../eeprom.h"
#include "../tuner/tuner.h"
#include "../display.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    lc = new LcdConverter();

    /* Create hex table */
    wgtHexTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    wgtHexTable->setFont(QFont(QFontDatabase::systemFont(QFontDatabase::FixedFont).family(), 9, QFont::Bold));
    wgtHexTable->verticalHeader()->setFont(QFont(QFontDatabase::systemFont(QFontDatabase::FixedFont).family(), 9, QFont::Bold));
    wgtHexTable->horizontalHeader()->setFont(QFont(QFontDatabase::systemFont(QFontDatabase::FixedFont).family(), 9, QFont::Bold));
    for (int y = 0; y < 64; y++) {
        wgtHexTable->setVerticalHeaderItem(y, new QTableWidgetItem(QString("%1").arg(y * 16, 4, 16, QChar('0')).toUpper()));
        for (int x = 0; x < 16; x++)
            wgtHexTable->setItem(y, x, new QTableWidgetItem());
    }
    for (int x = 0; x < 16; x++)
        wgtHexTable->setHorizontalHeaderItem(x, new QTableWidgetItem(QString("%1").arg(x, 0, 16).toUpper()));

    /* Create translations table */
    wgtTranslations->blockSignals(true);
    for (int y = 0; y < LABEL_END; y++)
        wgtTranslations->setItem(y, 0, new QTableWidgetItem());
    wgtTranslations->blockSignals(false);

    /* Load default eeprom file */
    readEepromFile(EEPROM_RESOURCE);
}

void MainWindow::updateHexTable(int pos)
{
    QTableWidgetItem *item = wgtHexTable->item(pos / 16, pos % 16);
    item->setText(eep.mid(pos, 1).toHex().toUpper());
    if (item->text() == "FF" && pos >= MODE_SND_END)
        item->setTextColor(Qt::gray);
    else if (item->text() == "00" && (pos) >= EEPROM_LABELS_ADDR)
        item->setTextColor(Qt::blue);
    else
        item->setTextColor(Qt::black);
}

void MainWindow::updateHexTable()
{
    for (int pos = 0; pos < 1024; pos++)
        updateHexTable(pos);
}

void MainWindow::readEepromFile(QString name)
{
    /* Reading file to QByteArray buffer */

    QFile file(name);

    if (!file.open(QIODevice::ReadOnly))
        return;
    if (name != EEPROM_RESOURCE) {
        actionSaveEeprom->setEnabled(true);
        fileName = name;
        Ui_MainWindow::statusBar->showMessage(
                    tr("File") + " " + fileName + " " + tr("loaded"));
    } else {
        actionSaveEeprom->setEnabled(false);
        fileName.clear();
        Ui_MainWindow::statusBar->showMessage("Default eeprom loaded");
    }

    eep = file.readAll();
    file.close();
    updateHexTable();

    // Processing translations

    QBuffer buffer(&eep);
    char ch;
    int pos, len;

    /* Load text labels */
    wgtTranslations->blockSignals(true);

    buffer.open(QIODevice::ReadOnly);
    buffer.seek(EEPROM_LABELS_ADDR);

    pos = buffer.pos();
    len = 0;
    buffer.getChar(&ch);

    for (int i = 0; i < LABEL_END && buffer.pos() < EEPROM_SIZE; i++) {
        while (ch == 0x00 && buffer.pos() < EEPROM_SIZE) {
            pos = buffer.pos();
            len = 0;
            buffer.getChar(&ch);
        }
        while (ch != 0x00 && buffer.pos() < EEPROM_SIZE) {
            buffer.getChar(&ch);
            len++;
        }
        wgtTranslations->item(i, 0)->setText(lc->decode(eep.mid(pos, len), LcdConverter::MAP_KS0066_RU));
    }
    wgtTranslations->blockSignals(false);

    buffer.close();

    // Processing audioprocessor

    int proc = eep[EEPROM_AUDIOPROC];
    if (proc >= AUDIOPROC_END)
        proc = AUDIOPROC_TDA7439;
    setAudioproc(proc);

    // Processing tuner
    int tuner = eep[EEPROM_FM_TUNER];
    if (tuner >= TUNER_END)
        tuner = TUNER_TEA5767;
    setTuner(tuner);

    // Processing other functions
    setOther();
}

void MainWindow::saveEepromFile(QString name)
{
    fileName = name;

    QFile file(name);
    if (!file.open(QIODevice::WriteOnly)) {
        Ui_MainWindow::statusBar->showMessage(tr("Can't save") + " " + name);
        return;
    }
    file.write(eep);
    file.close();
    Ui_MainWindow::statusBar->showMessage(tr("Saved as") + " " + name);

}

void MainWindow::setAudioParam(QDoubleSpinBox *spb, double min, double max, double step, int param)
{
    spb->setRange(min, max);
    spb->setSingleStep(step);
    spb->setValue(eep[EEPROM_VOLUME + param] * step);
}

void MainWindow::openEeprom()
{
    QString name = QFileDialog::getOpenFileName(this,
        tr("Open eeprom binary"),
        "../eeprom/",
        tr("EEPROM files (*.bin);;All files (*.*)"));

    readEepromFile(name);
}

void MainWindow::saveEeprom()
{
    saveEepromFile(fileName);
}

void MainWindow::saveEepromAs()
{
    QString name = QFileDialog::getSaveFileName(this,
        tr("Save eeprom binary"),
        "../eeprom/" + fileName,
        tr("EEPROM files (*.bin)"));

    if (name.isEmpty())
        return;

    saveEepromFile(name);
}

void MainWindow::loadDefaultEeprom()
{
    readEepromFile(EEPROM_RESOURCE);
}

void MainWindow::updateTranslation(int row, int column)
{
    Q_UNUSED(row); Q_UNUSED(column);

    QBuffer buffer(&eep);

    buffer.open(QIODevice::WriteOnly);
    buffer.seek(EEPROM_LABELS_ADDR);

    for (int i = 0; i < LABEL_END; i++) {
        QString str = wgtTranslations->item(i, 0)->text();
        if (str.isEmpty())
            str = " ";
        buffer.write(lc->encode(str, LcdConverter::MAP_KS0066_RU));
        buffer.putChar('\0');
    }

    while (buffer.pos() < EEPROM_SIZE) {
        buffer.putChar(0xFF);
    }

    buffer.close();

    updateHexTable();
}

void MainWindow::setAudioproc(int proc)
{
    cbxAudioproc->setCurrentIndex(proc);

    wgtVolume->hide();
    wgtBass->hide();
    wgtMiddle->hide();
    wgtTreble->hide();
    wgtPreamp->hide();
    wgtFrontrear->hide();
    wgtBalance->hide();
    wgtCenter->hide();
    wgtSubwoofer->hide();
    wgtGain0->hide();
    wgtGain1->hide();
    wgtGain2->hide();
    wgtGain3->hide();
    wgtGain4->hide();
    wgtLoudness->hide();
    wgtSurround->hide();
    wgtEffect3d->hide();
    wgtToneDefeat->hide();
    wgtInput->hide();
    cbxInput->clear();

    /* Handle loudness/surround/effect3d/tone_defeat*/
    switch (proc) {
    case AUDIOPROC_TDA7313:
    case AUDIOPROC_TDA7314:
    case AUDIOPROC_TDA7315:
    case AUDIOPROC_PT2314:
        wgtLoudness->show();
        cbxLoudness->setCurrentIndex(eep[EEPROM_LOUDNESS]);
        break;
    case AUDIOPROC_PT232X:
        wgtSurround->show();
        cbxSurround->setCurrentIndex(eep[EEPROM_SURROUND]);
        wgtEffect3d->show();
        cbxEffect3d->setCurrentIndex(eep[EEPROM_EFFECT3D]);
        wgtToneDefeat->show();
        cbxToneDefeat->setCurrentIndex(eep[EEPROM_TONE_DEFEAT]);
        break;
    }

    /* Handle maximum inputs */
    switch (proc) {
    case AUDIOPROC_PT232X:
        cbxInput->insertItem(0, "Input 5");
    case AUDIOPROC_TDA7439:
    case AUDIOPROC_TDA7312:
    case AUDIOPROC_TDA7318:
    case AUDIOPROC_PT2314:
        cbxInput->insertItem(0, "Input 4");
    case AUDIOPROC_TDA7313:
        cbxInput->insertItem(0, "Input 3");
        cbxInput->insertItem(0, "Input 2");
    default:
        cbxInput->insertItem(0, "Input 1");
        wgtInput->show();
        setInput(eep[EEPROM_INPUT]);
        cbxInput->setCurrentIndex(eep[EEPROM_INPUT]);
        break;
    }

    /* Common TDA73x1 audio parameters */
    switch (proc) {
    case AUDIOPROC_TDA7312:
    case AUDIOPROC_TDA7313:
    case AUDIOPROC_TDA7314:
    case AUDIOPROC_TDA7315:
    case AUDIOPROC_TDA7318:
    case AUDIOPROC_PT2314:
        wgtVolume->show();
        setAudioParam(dsbVolume, -78.5, 0, 1.25, MODE_SND_VOLUME);
        wgtBass->show();
        setAudioParam(dsbBass, -14, 14, 2, MODE_SND_BASS);
        wgtTreble->show();
        setAudioParam(dsbTreble, -14, 14, 2, MODE_SND_TREBLE);
        wgtBalance->show();
        setAudioParam(dsbBalance, -18.75, 18.75, 1.25, MODE_SND_BALANCE);
        break;
    }

    switch (proc) {
    case AUDIOPROC_TDA7439:
        wgtVolume->show();
        setAudioParam(dsbVolume, -79, 0, 1, MODE_SND_VOLUME);
        wgtBass->show();
        setAudioParam(dsbBass, -14, 14, 2, MODE_SND_BASS);
        wgtMiddle->show();
        setAudioParam(dsbMiddle, -14, 14, 2, MODE_SND_MIDDLE);
        wgtTreble->show();
        setAudioParam(dsbTreble, -14, 14, 2, MODE_SND_TREBLE);
        wgtPreamp->show();
        setAudioParam(dsbPreamp, -47, 0, 1, MODE_SND_PREAMP);
        wgtBalance->show();
        setAudioParam(dsbBalance, -15, 15, 1, MODE_SND_BALANCE);
        wgtGain0->show();
        setAudioParam(dsbGain0, 0, 30, 2, MODE_SND_GAIN0);
        wgtGain1->show();
        setAudioParam(dsbGain1, 0, 30, 2, MODE_SND_GAIN1);
        wgtGain2->show();
        setAudioParam(dsbGain2, 0, 30, 2, MODE_SND_GAIN2);
        wgtGain3->show();
        setAudioParam(dsbGain3, 0, 30, 2, MODE_SND_GAIN3);
        break;
    case AUDIOPROC_TDA7313:
        wgtFrontrear->show();
        setAudioParam(dsbFrontrear, -18.75, 18.75, 1.25, MODE_SND_FRONTREAR);
        wgtGain0->show();
        setAudioParam(dsbGain0, 0, 11.25, 3.75, MODE_SND_GAIN0);
        wgtGain1->show();
        setAudioParam(dsbGain1, 0, 11.25, 3.75, MODE_SND_GAIN1);
        wgtGain2->show();
        setAudioParam(dsbGain2, 0, 11.25, 3.75, MODE_SND_GAIN2);
        break;
    case AUDIOPROC_TDA7314:
        wgtFrontrear->show();
        setAudioParam(dsbFrontrear, -18.75, 18.75, 1.25, MODE_SND_FRONTREAR);
        wgtGain0->show();
        setAudioParam(dsbGain0, 0, 18.75, 6.25, MODE_SND_GAIN0);
        break;
    case AUDIOPROC_TDA7318:
        wgtFrontrear->show();
        setAudioParam(dsbFrontrear, -18.75, 18.75, 1.25, MODE_SND_FRONTREAR);
        wgtGain0->show();
        setAudioParam(dsbGain0, 0, 18.75, 6.25, MODE_SND_GAIN0);
        wgtGain1->show();
        setAudioParam(dsbGain1, 0, 18.75, 6.25, MODE_SND_GAIN1);
        wgtGain2->show();
        setAudioParam(dsbGain2, 0, 18.75, 6.25, MODE_SND_GAIN2);
        wgtGain3->show();
        setAudioParam(dsbGain3, 0, 18.75, 6.25, MODE_SND_GAIN3);
        break;
    case AUDIOPROC_PT2314:
        wgtFrontrear->show();
        setAudioParam(dsbFrontrear, -18.75, 18.75, 1.25, MODE_SND_FRONTREAR);
        wgtGain0->show();
        setAudioParam(dsbGain0, 0, 11.25, 3.75, MODE_SND_GAIN0);
        wgtGain1->show();
        setAudioParam(dsbGain1, 0, 11.25, 3.75, MODE_SND_GAIN1);
        wgtGain2->show();
        setAudioParam(dsbGain2, 0, 11.25, 3.75, MODE_SND_GAIN2);
        wgtGain3->show();
        setAudioParam(dsbGain3, 0, 11.25, 3.75, MODE_SND_GAIN3);
        break;
    case AUDIOPROC_TDA7448:
        wgtVolume->show();
        setAudioParam(dsbVolume, -79, 0, 1, MODE_SND_VOLUME);
        wgtFrontrear->show();
        setAudioParam(dsbFrontrear, -7, 7, 1, MODE_SND_FRONTREAR);
        wgtBalance->show();
        setAudioParam(dsbBalance, -7, 7, 1, MODE_SND_BALANCE);
        wgtCenter->show();
        setAudioParam(dsbCenter, -15, 0, 1, MODE_SND_CENTER);
        wgtSubwoofer->show();
        setAudioParam(dsbSubwoofer, -15, 0, 1, MODE_SND_SUBWOOFER);
        break;
    case AUDIOPROC_PT232X:
        wgtVolume->show();
        setAudioParam(dsbVolume, -79, 0, 1, MODE_SND_VOLUME);
        wgtBass->show();
        setAudioParam(dsbBass, -14, 14, 2, MODE_SND_BASS);
        wgtMiddle->show();
        setAudioParam(dsbMiddle, -14, 14, 2, MODE_SND_MIDDLE);
        wgtTreble->show();
        setAudioParam(dsbTreble, -14, 14, 2, MODE_SND_TREBLE);
        wgtFrontrear->show();
        setAudioParam(dsbFrontrear, -7, 7, 1, MODE_SND_FRONTREAR);
        wgtBalance->show();
        setAudioParam(dsbBalance, -7, 7, 1, MODE_SND_BALANCE);
        wgtCenter->show();
        setAudioParam(dsbCenter, -15, 0, 1, MODE_SND_CENTER);
        wgtSubwoofer->show();
        setAudioParam(dsbSubwoofer, -15, 0, 1, MODE_SND_SUBWOOFER);
        wgtGain0->show();
        setAudioParam(dsbGain0, 0, 6, 6, MODE_SND_GAIN4);
        wgtGain1->show();
        setAudioParam(dsbGain1, 0, 6, 6, MODE_SND_GAIN4);
        wgtGain2->show();
        setAudioParam(dsbGain2, 0, 6, 6, MODE_SND_GAIN4);
        wgtGain3->show();
        setAudioParam(dsbGain3, 0, 6, 6, MODE_SND_GAIN4);
        wgtGain4->show();
        setAudioParam(dsbGain4, 0, 6, 6, MODE_SND_GAIN4);
        break;
    case AUDIOPROC_PGA2310:
        wgtVolume->show();
        setAudioParam(dsbVolume, -96, 31, 1, MODE_SND_VOLUME);
        wgtBalance->show();
        setAudioParam(dsbBalance, -15, 15, 1, MODE_SND_BALANCE);
        break;
    }

    eep[EEPROM_AUDIOPROC] = proc;
    updateHexTable(EEPROM_AUDIOPROC);
}

void MainWindow::setVolume(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_VOLUME] = static_cast<char>(value / dsbVolume->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_VOLUME);
}

void MainWindow::setBass(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_BASS] = static_cast<char>(value / dsbBass->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_BASS);
}

void MainWindow::setMiddle(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_MIDDLE] = static_cast<char>(value / dsbMiddle->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_MIDDLE);
}

void MainWindow::setTreble(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_TREBLE] = static_cast<char>(value / dsbTreble->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_TREBLE);
}

void MainWindow::setPreamp(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_PREAMP] = static_cast<char>(value / dsbPreamp->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_PREAMP);
}

void MainWindow::setFrontrear(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_FRONTREAR] = static_cast<char>(value / dsbFrontrear->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_FRONTREAR);
}

void MainWindow::setBalance(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_BALANCE] = static_cast<char>(value / dsbBalance->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_BALANCE);
}

void MainWindow::setCenter(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_CENTER] = static_cast<char>(value / dsbCenter->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_CENTER);
}

void MainWindow::setSubwoofer(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_SUBWOOFER] = static_cast<char>(value / dsbSubwoofer->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_SUBWOOFER);
}

void MainWindow::setGain0(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_GAIN0] = static_cast<char>(value / dsbGain0->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_GAIN0);
}

void MainWindow::setGain1(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_GAIN1] = static_cast<char>(value / dsbGain1->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_GAIN1);
}

void MainWindow::setGain2(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_GAIN2] = static_cast<char>(value / dsbGain2->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_GAIN2);
}

void MainWindow::setGain3(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_GAIN3] = static_cast<char>(value / dsbGain3->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_GAIN3);
}

void MainWindow::setGain4(double value)
{
    eep[EEPROM_VOLUME + MODE_SND_GAIN4] = static_cast<char>(value / dsbGain4->singleStep());
    updateHexTable(EEPROM_VOLUME + MODE_SND_GAIN4);
}

void MainWindow::setInput(int value)
{
    if (value >= cbxInput->count())
        value = cbxInput->count() - 1;
    eep[EEPROM_INPUT] = (char)value;
    updateHexTable(EEPROM_INPUT);
    cbxInputIcon->setCurrentIndex(eep[EEPROM_INPUT_ICONS + eep[EEPROM_INPUT]]);
}

void MainWindow::setInputIcon(int value)
{
    if (value >= cbxInputIcon->count())
        value = cbxInputIcon->count() - 1;
    eep[EEPROM_INPUT_ICONS + eep[EEPROM_INPUT]] = (char)value;
    updateHexTable(EEPROM_INPUT_ICONS + eep[EEPROM_INPUT]);
}

void MainWindow::setLoudness(int value)
{
    eep[EEPROM_LOUDNESS] = value;
    updateHexTable(EEPROM_LOUDNESS);
}

void MainWindow::setSurround(int value)
{
    eep[EEPROM_SURROUND] = value;
    updateHexTable(EEPROM_SURROUND);
}

void MainWindow::setEffect3d(int value)
{
    eep[EEPROM_EFFECT3D] = value;
    updateHexTable(EEPROM_EFFECT3D);
}

void MainWindow::setToneDefeat(int value)
{
    eep[EEPROM_TONE_DEFEAT] = value;
    updateHexTable(EEPROM_TONE_DEFEAT);
}

double MainWindow::getFreq(int pos)
{
    double freq;

    freq = (unsigned char)eep[pos];
    freq += (unsigned char)eep[pos + 1] * 256;
    freq /= 100;

    return freq;
}

void MainWindow::setFreq(double value, int pos)
{
    int freq = value * 100;

    eep[pos] = (char)(freq & 0x00FF);
    eep[pos + 1] = (char)((freq & 0xFF00) >> 8);

    updateHexTable(pos);
    updateHexTable(pos + 1);
}

void MainWindow::about()
{
    AboutDialog dlg;

    dlg.exec();
}

void MainWindow::aboutQt()
{
    qApp->aboutQt();
}

void MainWindow::setTuner(int tuner)
{
    double fmStep = (double)eep[EEPROM_FM_STEP] / 100;

    cbxTuner->setCurrentIndex(tuner);
    wgtFmfreq->hide();
    wgtFmstep->hide();
    wgtFmmono->hide();
    wgtFmctrl->hide();

    switch (tuner) {
    case TUNER_TEA5767:
        wgtFmctrl->show();
        cbxFmctrlHcc->setChecked(eep[EEPROM_FM_CTRL] & TEA5767_CTRL_HCC);
        cbxFmctrlSnc->setChecked(eep[EEPROM_FM_CTRL] & TEA5767_CTRL_SNC);
        cbxFmctrlSm->setChecked(eep[EEPROM_FM_CTRL] & TEA5767_CTRL_SMUTE);
        cbxFmctrlDtc->setChecked(eep[EEPROM_FM_CTRL] & TEA5767_CTRL_DTC);
        cbxFmctrlBl->setChecked(eep[EEPROM_FM_CTRL] & TEA5767_CTRL_BL);
        cbxFmctrlPllref->setChecked(eep[EEPROM_FM_CTRL] & TEA5767_CTRL_PLLREF);
        cbxFmctrlXtal->setChecked(eep[EEPROM_FM_CTRL] & TEA5767_CTRL_XTAL);
    case TUNER_RDA5807:
        wgtFmmono->show();
        setFmmono(eep[EEPROM_FM_MONO]);
        cbxFmmono->setCurrentIndex(eep[EEPROM_FM_MONO]);
    case TUNER_TUX032:
    case TUNER_LM7001:
        wgtFmfreq->show();
        dsbFmfreq->setSingleStep(fmStep);
        dsbFmfreq->setValue(getFreq(EEPROM_FM_FREQ));
        wgtFmstep->show();
        dsbFmstep->setValue(fmStep);
        break;
    }

    eep[EEPROM_FM_TUNER] = tuner;
    updateHexTable(EEPROM_FM_TUNER);
}

void MainWindow::setFmfreq(double value)
{
    setFreq(value, EEPROM_FM_FREQ);
}

void MainWindow::setFmstep(double value)
{
    dsbFmfreq->setSingleStep(value);
    eep[EEPROM_FM_STEP] = value * 100;
    updateHexTable(EEPROM_FM_STEP);
}

void MainWindow::setFmmono(int value)
{
    if (value)
        eep[EEPROM_FM_MONO] = 0x01;
    else
        eep[EEPROM_FM_MONO] = 0x00;
    updateHexTable(EEPROM_FM_MONO);
}

void MainWindow::setFmctrl()
{
    char ctrl = 0;

    if (cbxFmctrlHcc->isChecked()) ctrl |= TEA5767_CTRL_HCC;
    if (cbxFmctrlSnc->isChecked()) ctrl |= TEA5767_CTRL_SNC;
    if (cbxFmctrlSm->isChecked()) ctrl |= TEA5767_CTRL_SMUTE;
    if (cbxFmctrlDtc->isChecked()) ctrl |= TEA5767_CTRL_DTC;
    if (cbxFmctrlBl->isChecked()) ctrl |= TEA5767_CTRL_BL;
    if (cbxFmctrlPllref->isChecked()) ctrl |= TEA5767_CTRL_PLLREF;
    if (cbxFmctrlXtal->isChecked()) ctrl |= TEA5767_CTRL_XTAL;

    eep[EEPROM_FM_CTRL] = ctrl;
    updateHexTable(EEPROM_FM_CTRL);
}

void MainWindow::setOther()
{
    setSpmode(eep[EEPROM_SP_MODE]);
    cbxSpmode->setCurrentIndex(eep[EEPROM_SP_MODE]);

    setSpspeed(eep[EEPROM_FALL_SPEED]);
    cbxSpspeed->setCurrentIndex(eep[EEPROM_FALL_SPEED]);

    setBrstby(eep[EEPROM_BR_STBY]);
    sbxBrstby->setValue(eep[EEPROM_BR_STBY]);

    setEncres(eep[EEPROM_ENC_RES]);
    sbxEncres->setValue(eep[EEPROM_ENC_RES]);

    setAdcleft((unsigned char)eep[EEPROM_ADC_CORR_L] - 128);
    sbxAdcleft->setValue((unsigned char)eep[EEPROM_ADC_CORR_L] - 128);

    setAdcright((unsigned char)eep[EEPROM_ADC_CORR_L] - 128);
    sbxAdcright->setValue((unsigned char)eep[EEPROM_ADC_CORR_R] - 128);

    setExtfunc(eep[EEPROM_EXT_FUNC]);
    cbxExtfunc->setCurrentIndex(eep[EEPROM_EXT_FUNC]);

    setThreshold(eep[EEPROM_TEMP_TH]);
    sbxThreshold->setValue(eep[EEPROM_TEMP_TH]);

    setSilence((unsigned char)eep[EEPROM_SILENCE_TIMER]);
    sbxSilence->setValue((unsigned char)eep[EEPROM_SILENCE_TIMER]);
}

void MainWindow::setSpmode(int value)
{
    if (value >= SP_MODE_END)
        value = SP_MODE_STEREO;
    eep[EEPROM_SP_MODE] = (char)value;
    updateHexTable(EEPROM_SP_MODE);
}

void MainWindow::setSpspeed(int value)
{
    if (value >= FALL_SPEED_END)
        value = FALL_SPEED_LOW;
    eep[EEPROM_FALL_SPEED] = (char)value;
    updateHexTable(EEPROM_FALL_SPEED);
}

void MainWindow::setBrstby(int value)
{
    if (value > sbxBrstby->maximum())
        value = 1;
    eep[EEPROM_BR_STBY] = (char)value;
    updateHexTable(EEPROM_BR_STBY);
}

void MainWindow::setEncres(int value)
{
    if (value > sbxEncres->maximum())
        value = sbxEncres->maximum();
    if (value < sbxEncres->minimum())
        value = sbxEncres->minimum();
    eep[EEPROM_ENC_RES] = (char)value;
    updateHexTable(EEPROM_ENC_RES);
}

void MainWindow::setAdcleft(int value)
{
    if (value > sbxAdcleft->maximum())
        value = sbxAdcleft->maximum();
    if (value < sbxAdcleft->minimum())
        value = sbxAdcleft->minimum();
    eep[EEPROM_ADC_CORR_L] = (char)value + 128;
    updateHexTable(EEPROM_ADC_CORR_L);
}

void MainWindow::setAdcright(int value)
{
    if (value > sbxAdcright->maximum())
        value = sbxAdcright->maximum();
    if (value < sbxAdcright->minimum())
        value = sbxAdcright->minimum();
    eep[EEPROM_ADC_CORR_R] = (char)value + 128;
    updateHexTable(EEPROM_ADC_CORR_R);
}

void MainWindow::setExtfunc(int value)
{
    if (value >= 3)
        value = 0;
    eep[EEPROM_EXT_FUNC] = (char)value;
    updateHexTable(EEPROM_EXT_FUNC);
}

void MainWindow::setThreshold(int value)
{
    if (value > sbxThreshold->maximum())
        value = sbxThreshold->maximum();
    if (value < sbxThreshold->minimum())
        value = sbxThreshold->minimum();
    eep[EEPROM_TEMP_TH] = (char)value;
    updateHexTable(EEPROM_TEMP_TH);
}

void MainWindow::setSilence(int value)
{
    if (value > sbxSilence->maximum())
        value = sbxSilence->maximum();
    if (value < sbxSilence->minimum())
        value = sbxSilence->minimum();
    eep[EEPROM_SILENCE_TIMER] = (unsigned char)value;
    updateHexTable(EEPROM_SILENCE_TIMER);

}
