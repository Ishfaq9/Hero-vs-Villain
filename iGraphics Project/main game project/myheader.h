#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int cordinate_x, cordinate_y;
int dx, dy;

void ReactangleChnage() {
	cordinate_x += dx;
	 cordinate_y += dy;

	if ( cordinate_x >= 350 ||  cordinate_x <= 0)
		dx = -dx;
	if ( cordinate_y >= 300 ||  cordinate_y <= 0)
		dy = -dy;
}

#endif // !MYHEADER_H_INCLUDED
