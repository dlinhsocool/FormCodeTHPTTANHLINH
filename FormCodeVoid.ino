 //code cam bien rung
 if(chuoi[0] == 'id'){
      chuoi.remove(0,1);
      SensorVal_PIN = chuoi.toInt();
      if(SensorVal_PIN<900){
        digitalWrite(Relay, HIGH);  
      }
    }
 //code cam bien chay
    if(chuoi[0] == 'id'){
      chuoi.remove(0,1);
      SensorVal_PIN = chuoi.toInt();
      if(SensorVal_PIN>480){
        digitalWrite(Relay, HIGH);  
      }
    }
