 //code cam bien rung
 if(chuoi[0] == 'id'){
      chuoi.remove(0,1);
      sensorVal = chuoi.toInt();
      if(sensorVal<900){
        digitalWrite(Relay, HIGH);  
      }
    }
 //code cam bien chay
    if(chuoi[0] == 'id'){
      chuoi.remove(0,1);
      sensorVal_2 = chuoi.toInt();
      if(sensorVal_2>480){
        digitalWrite(Relay, HIGH);  
      }
    }
