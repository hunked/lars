void doEncButtons() { // encoder/button press handling
  if (!doEG) {
    if (enc1.isLeft()) changeValue(0, 0);
    else if (enc1.isLeftH()) changeValue(0, 10);
    else if (enc1.isRight()) changeValue(0, 1);
    else if (enc1.isRightH()) changeValue(0, 11);
    else if (enc1.isClick()) changeValue(0, 12);

    if (enc2.isLeft()) changeValue(1, 0);
    else if (enc2.isLeftH()) changeValue(1, 10);
    else if (enc2.isRight()) changeValue(1, 1);
    else if (enc2.isRightH()) changeValue(1, 11);
    else if (enc2.isClick()) changeValue(1, 12);

    if (enc3.isLeft()) changeValue(2, 0);
    else if (enc3.isLeftH()) changeValue(2, 10);
    else if (enc3.isRight()) changeValue(2, 1);
    else if (enc3.isRightH()) changeValue(2, 11);
    else if (enc3.isClick()) changeValue(2, 12);

    if (enc4.isLeft()) changeValue(3, 0);
    else if (enc4.isLeftH()) changeValue(3, 10);
    else if (enc4.isRight()) changeValue(3, 1);
    else if (enc4.isRightH()) changeValue(3, 11);
    else if (enc4.isClick()) changeValue(3, 12);
  }
  else if (doEG) { // reverse function (change 10 at a time) for EG editing for quicker value changes
    if (enc1.isLeft()) changeValue(0, 10);
    else if (enc1.isLeftH()) changeValue(0, 0);
    else if (enc1.isRight()) changeValue(0, 11);
    else if (enc1.isRightH()) changeValue(0, 1);
    else if (enc1.isClick()) changeValue(0, 12);

    if (enc2.isLeft()) changeValue(1, 10);
    else if (enc2.isLeftH()) changeValue(1, 0);
    else if (enc2.isRight()) changeValue(1, 11);
    else if (enc2.isRightH()) changeValue(1, 1);
    else if (enc2.isClick()) changeValue(1, 12);

    if (enc3.isLeft()) changeValue(2, 10);
    else if (enc3.isLeftH()) changeValue(2, 1);
    else if (enc3.isRight()) changeValue(2, 11);
    else if (enc3.isRightH()) changeValue(2, 1);
    else if (enc3.isClick()) changeValue(2, 12);

    if (enc4.isLeft()) changeValue(3, 10);
    else if (enc4.isLeftH()) changeValue(3, 1);
    else if (enc4.isRight()) changeValue(3, 11);
    else if (enc4.isRightH()) changeValue(3, 1);
    else if (enc4.isClick()) changeValue(3, 12);
  }
}

void doTopButtons() { // top row button handling
  if (tbtn1.isClick()) { // decrease patch number
    if (presetType != 3) {
      patchNum--;
      if (patchNum < 0) patchNum = 127;
      loadPatch();
      displayStatus(2);
    }
    else {
      levelEG = !levelEG;
      doPreset = true;
    }
  }
  else if (tbtn1.isHold()) { // hold button to decrease patch number
    if (presetType != 3) {
      patchNum -= 1;
      if (patchNum < 0) patchNum = 127;
      loadPatch();
      displayStatus(2);
    }
  }
  else if (tbtn2.isClick()) { // increase patch number - use a double click to prevent accidental patch change/loss of current patch
    if (presetType != 3) {
      patchNum++;
      if (patchNum > 127) patchNum = 0;
      loadPatch();
      displayStatus(2);
    }
  }
  else if (tbtn2.isHold()) { // hold button to increase patch number
    if (presetType != 3) {
      patchNum += 1;
      if (patchNum > 127) patchNum = 0;
      loadPatch();
      displayStatus(2);
    }
  }
  else if (tbtn3.isPress()) { // switch between level and time edit when editing EG
    if (presetType == 3) { // only when in EG mode
      levelEG = !levelEG;
      doPreset = true;
    }
  }
  else if (tbtn3.isHold()) { // load patch from EEPROM
    loadPatch();
    clearText(0);
    displayText(10);
    delay(1000);
    if (presetType != 3) displayStatus(1);
  }
  else if (tbtn3.hasClicks(5)) { // initialize patch
    initPatch();
    displayText(12);
    delay(1000);
    if (presetType != 3) displayStatus(1);
  }
  else if (tbtn4.isHold()) { // save patch to EEPROM
    if (changeSave()) displayText(11);
    delay(1000);
    if (presetType != 3) displayStatus(0);
    doPreset = true;
  }
  else if (tbtn4.hasClicks(3)) {
    if (changeMIDI()) displayText(13);
    delay(1000);
    if (presetType != 3) displayStatus(0);
    doPreset = true;
  }

}

void doBotButtons() { // bottom row button handling
  if (bbtn1.isPress()) {
    if (presetType == 0) {
      presetNum[0]++;
      if (presetNum[0] > 21) presetNum[0] = 0;
    } else presetType = 0;
    doPreset = true;
    doClear();
  }
  else if (bbtn1.hasClicks(2)) {
    if (presetType == 0) {
      presetNum[0]--;
      if (presetNum[0] < 0) presetNum[0] = 21;
    } else presetType = 0;
    doPreset = true;
    doClear();
  }
  else if (bbtn1.isHold()) {
    presetType = 0;
    presetNum[0] = 0;
    doPreset = true;
    doClear();
  }

  else if (bbtn2.isPress()) {
    if (presetType == 1) {
      presetNum[1]++;
      if (presetNum[1] > 3) presetNum[1] = 0;
    } else presetType = 1;
    doPreset = true;
    doClear();
  }
  else if (bbtn2.hasClicks(2)) {
    if (presetType == 1) {
      presetNum[1]--;
      if (presetNum[1] < 0) presetNum[1] = 3;
    } else presetType = 1;
    doPreset = true;
    doClear();
  }
  else if (bbtn2.isHold()) {
    presetType = 1;
    presetNum[1] = 0;
    doPreset = true;
    doClear();
  }

  else if (bbtn3.isPress()) {
    if (presetType == 2) {
      presetNum[2]++;
      if (presetNum[2] > 12) presetNum[2] = 0;
    } else presetType = 2;
    doPreset = true;
    doClear();
  }
  else if (bbtn3.hasClicks(2)) {
    if (presetType == 2) {
      presetNum[2]--;
      if (presetNum[2] < 0) presetNum[2] = 12;
    } else presetType = 2;
    doPreset = true;
    doClear();
  }
  else if (bbtn3.isHold()) {
    presetType = 2;
    presetNum[2] = 0;
    doPreset = true;
    doClear();
  }

  else if (bbtn4.isPress()) { // envelope generator
    if (presetType == 3) {
      presetNum[3]++;
      if (presetNum[3] > 6) presetNum[3] = 0;
    } else presetType = 3;
    doPreset = true;
  }
  else if (bbtn4.hasClicks(2)) {
    if (presetType == 3) {
      presetNum[3]--;
      if (presetNum[3] < 0) presetNum[3] = 6;
    } else presetType = 3;
    doPreset = true;
  }
  else if (bbtn4.isHold()) {
    presetType = 3;
    presetNum[3] = 0;
    doPreset = true;

  }

  else if (bbtn5.isPress()) {
    if (presetType == 4) {
      presetNum[4]++;
      if (presetNum[4] > 18) presetNum[4] = 0;
    } else presetType = 4;
    doPreset = true;
    doClear();
  }
  else if (bbtn5.hasClicks(2)) {
    if (presetType == 4) {
      presetNum[4]--;
      if (presetNum[4] < 0) presetNum[4] = 18;
    } else presetType = 4;
    doPreset = true;
    doClear();
  }
  else if (bbtn5.isHold()) {
    presetType = 4;
    presetNum[4] = 0;
    doPreset = true;
    doClear();
  }

  else if (bbtn6.isPress()) {
    if (presetType == 5) {
      presetNum[5]++;
      if (presetNum[5] > 5) presetNum[5] = 0;
    } else presetType = 5;
    doPreset = true;
    doClear();
  }
  else if (bbtn6.hasClicks(2)) {
    if (presetType == 5) {
      presetNum[5]--;
      if (presetNum[5] < 0) presetNum[5] = 5;
    } else presetType = 5;
    doPreset = true;
    doClear();
  }
  else if (bbtn6.isHold()) {
    presetType = 5;
    presetNum[5] = 0;
    doPreset = true;
    doClear();
  }
}

void doClear() {
  if (doEG) {
    doEG = false;
    display.clearDisplay();
  }
}

void doScrButtons() { // handle buttons around screen (not encoders)
  if (presetType != 3) { // if not in ADSR editor
    if (sbtn1.isPress()) {
      if (presetType == 11) {
        presetNum[11]++;
        if (presetNum[11] > 3) presetNum[11] = 0;
      } else presetType = 11;
      doPreset = true;
    }
    else if (sbtn1.isHold()) {
      presetType = 11;
      presetNum[11] = 0;
      doPreset = true;
    }

    else if (sbtn2.isPress()) {
      if (presetType == 12) {
        presetNum[12]++;
        if (presetNum[12] > 3) presetNum[12] = 0;
      } else presetType = 12;
      doPreset = true;
    }
    else if (sbtn2.isHold()) {
      presetType = 12;
      presetNum[12] = 0;
      doPreset = true;
    }

    else if (sbtn3.isPress()) {
      if (presetType == 13) {
        presetNum[13]++;
        if (presetNum[13] > 3) presetNum[13] = 0;
      } else presetType = 13;
      doPreset = true;
    }
    else if (sbtn3.isHold()) {
      presetType = 13;
      presetNum[13] = 0;
      doPreset = true;
    }

    else if (sbtn4.isPress()) {
      if (presetType == 14) {
        presetNum[14]++;
        if (presetNum[14] > 3) presetNum[14] = 0;
      } else presetType = 14;
      doPreset = true;
    }
    else if (sbtn4.isHold()) {
      presetType = 14;
      presetNum[14] = 0;
      doPreset = true;
    }
  }
  else if (presetType == 3) {
    if (sbtn1.isPress()) {
      editEG[0] = !editEG[0];
      doPreset = true;
    }
    else if (sbtn2.isPress()) {
      editEG[1] = !editEG[1];
      doPreset = true;
    }
    else if (sbtn3.isPress()) {
      editEG[2] = !editEG[2];
      doPreset = true;
    }
    else if (sbtn4.isPress()) {
      editEG[3] = !editEG[3];
      doPreset = true;
    }
  }
}

void encUpdate() { // pulls values from encoders/buttons, needs to be run as often as possible
  enc1.tick();
  enc2.tick();
  enc3.tick();
  enc4.tick();
  sbtn1.tick();
  sbtn2.tick();
  sbtn3.tick();
  sbtn4.tick();
  tbtn1.tick();
  tbtn2.tick();
  tbtn3.tick();
  tbtn4.tick();
  bbtn1.tick();
  bbtn2.tick();
  bbtn3.tick();
  bbtn4.tick();
  bbtn5.tick();
  bbtn6.tick();
}