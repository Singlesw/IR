#define irsend_var irsend

//hdmi_matrix_1 -      (address 0x00)

#define hdmi_matrix_1_a1        irsend_var.sendNEC(0xFFE01F, 32);  //A1               (command 0x07)
#define hdmi_matrix_1_a2        irsend_var.sendNEC(0xFFA857, 32);  //A2               (command 0x15)
#define hdmi_matrix_1_a3        irsend_var.sendNEC(0xFF906F, 32);  //A3               (command 0x09)
#define hdmi_matrix_1_a4        irsend_var.sendNEC(0xFF6897, 32);  //A4               (command 0x16)
#define hdmi_matrix_1_a5        irsend_var.sendNEC(0xFF9867, 32);  //A5               (command 0x19)
#define hdmi_matrix_1_a6        irsend_var.sendNEC(0xFFB04F, 32);  //A6               (command 0x0D)
#define hdmi_matrix_1_b1        irsend_var.sendNEC(0xFF10EF, 32);  //B1               (command 0x08)
#define hdmi_matrix_1_b2        irsend_var.sendNEC(0xFF38C7, 32);  //B2               (command 0x1C)
#define hdmi_matrix_1_b3        irsend_var.sendNEC(0xFF5AA5, 32);  //B3               (command 0x5A)
#define hdmi_matrix_1_b4        irsend_var.sendNEC(0xFF42BD, 32);  //B4               (command 0x42)
#define hdmi_matrix_1_b5        irsend_var.sendNEC(0xFF4AB5, 32);  //B5               (command 0x52)
#define hdmi_matrix_1_b6        irsend_var.sendNEC(0xFF52AD, 32);  //B6               (command 0x4A)
#define hdmi_matrix_1_power     irsend_var.sendNEC(0xFFA25D, 32);  //B6               (command 0x45)
