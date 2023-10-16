#include <GyverJoy.h>
#include <EncButton.h>


Button btn_b(9);
Button btn_r(10);
Button btn_j(8);
Button btn_e(7);

Encoder enc(2, 3);
GyverJoy jx(1);


void setup() {
  Serial.begin(115200);

  jx.calibrate();
  jx.exponent(GJ_CUBIC);

}
int enc_s = 0;
bool send = false;
void loop() {
  btn_b.tick();
  btn_r.tick();
  btn_e.tick();
  btn_j.tick();
  enc.tick();
  
  if (btn_b.click()){ // Click blue BTN (F key & G key)
    Serial.println("btn_f_clc");
    Serial.println("btn_g_clc");
  }
  if (btn_r.click()){  // Click red BTN (Z key)
    Serial.println("btn_i_clc");
  }
  if (btn_e.click()){ // Click enc BTN (E key)
    Serial.println("btn_e_clc");
  }
  if (btn_j.click()){ // Click joy BTN (E key)
    Serial.println("btn_z_clc");
  }

  if (enc.turn()){
     enc_s = enc_s + enc.dir();
     send = false;
     //Serial.println(enc.dir());
  }
  if (enc_s >= 3 && enc_s <= 7 && send != true) { // (T key)
     Serial.println("btn_t_clc");
     send = true;
  }
  if (enc_s <= -3 && enc_s >= -7 && send != true) { // (R key)
     Serial.println("btn_r_clc");
     send = true;
  }

  if (jx.tick()) {
    if (jx.value() >= 100 || jx.value()<= -100) {
      if (jx.value() >= 100) {
        Serial.println("btn_s_clc");
      }
      if (jx.value() <= -100) {
        Serial.println("btn_w_clc");
      }
       //Serial.println(jx.value());
      delay(250);
    }
   
  }
  
}
