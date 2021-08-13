if( getTextValue('[VSORRES_WEIGHT]')!='' &&  getTextValue('[VSORRES_HEIGHT]')!='') {
    if( getRadioValue('[VSORRESU_WEIGHT]')=='2' &&  getRadioValue('[VSORRESU_HEIGHT]')=='2') {
      // kg & cm
      setTextValue('[VSORRES_BMI]',
                    Math.round(parseFloat(((getTextValue('[VSORRES_WEIGHT]')/
                    Math.pow((getTextValue('[VSORRES_HEIGHT]') / 100)/1.0,2))))));
    } else if (getRadioValue('[VSORRESU_WEIGHT]')=='1' &&  getRadioValue('[VSORRESU_HEIGHT]')=='1') {
      // lbs & inch
      setTextValue('[VSORRES_BMI]',
                    Math.round(parseFloat((((getTextValue('[VSORRES_WEIGHT]') * 0.454)/
                    Math.pow(((getTextValue('[VSORRES_HEIGHT]') * 2.54) / 100)/1.0,2))))));
    } else if (getRadioValue('[VSORRESU_WEIGHT]')=='1' &&  getRadioValue('[VSORRESU_HEIGHT]')=='2') {
      // lbs & cm
      setTextValue('[VSORRES_BMI]',
                    Math.round(parseFloat((((getTextValue('[VSORRES_WEIGHT]') * 0.454)/
                    Math.pow((getTextValue('[VSORRES_HEIGHT]') / 100)/1.0,2))))));
    } else if (getRadioValue('[VSORRESU_WEIGHT]')=='2' &&  getRadioValue('[VSORRESU_HEIGHT]')=='1') {
      // kg & inch
      setTextValue('[VSORRES_BMI]',
                    Math.round(parseFloat(((getTextValue('[VSORRES_WEIGHT]')/
                    Math.pow(((getTextValue('[VSORRES_HEIGHT]') * 2.54) / 100)/1.0,2))))));
    }
  } else {
    setTextValue('[VSORRES_BMI]','');
  }