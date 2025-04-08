#ifndef DEFS__H
#define DEFS__H

const int CHIEU_RONG_MAN = 600;               //chiều rộng của màn hình chơi game là 600
const int CHIEU_CAO_MAN = 600;              //chiều cao của màn hình chơi game là 600
const char* WINDOW_TITLE = "Game X_O 2 nguoi :)))";
const int KICH_THUOC_O = 200;     //kích thước của ô là 200

enum TRANG_THAI{NONE = 0, X, O}; //chi tiết

TRANG_THAI BAN_CO[3][3] = {NONE}; // mảng 2 chiều thể hiện bàn cờ, ban đầu là ô trống

TRANG_THAI Luot_di = X; //lượt đi trước là người chơi x

#endif
