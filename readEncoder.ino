void encoder1() { // fungsi encoder
  int a = digitalRead(ENCOA1);
  if (a > 0) {
    pulse1 ++;
//    pulse1_pos;
  }
  else {
    pulse1 --;
  }
}
