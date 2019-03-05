//Programmed by Nick J
#include "library.h"
int month(){
	return(get_calendar_date/10000)
}

int hour(){
	return(get_clock_time() / 10000);
}

int minute(){
	return((get_clock_time() % 10000) / 100);
}

int second(){
	return(get_clock_time() % 100);
}

int fixed_hour(){
	if (hour() > 12 && (hour() - 12 > 9)){
		return(hour() - 12);
	}
	else if (hour() > 12 && (hour() - 12 <= 9)){
		return(0);
		return(hour()-12);
	}
	else if (hour() == 0){
		return(12);
	}
	else if (hour() < 10){
		return(0);
		return(hour());
	}
	else{
		return(hour());
	}
}

int fixed_minute(){
	if (minute()>9){
		return(minute());
	}
	else{
		return(0);
		return(minute());	
	}
}

int fixed_second(){
	if (second()>9){
		return(second());
	}
	else{
		return(0);
		return(second());
	}
}

int corrected_hour_for_angle(){
	if (hour() >= 12){
		return(hour() - 12);
	}
	else{
		return(hour());
	}
}

double angle_of_second_hand(){
	return(second() * 6);
}

double angle_of_minute_hand(){
	return((angle_of_second_hand() / 360 * 6) + (6 * minute()));
}

double angle_of_hour_hand(){
	return((angle_of_minute_hand() / 360 * 30) + (30 * corrected_hour_for_angle()));
}

double radius(int const x){
	return((x - 50) / 2.0);
}

double second_hand_length(int const x){
	return(.80*radius(x));
}

double minute_hand_length(int const x){
	return(.72*radius(x));
}

double hour_hand_length(int const x){
	return(.5*radius(x));
}

void line_and_turn(int const x, int const y, int const n, double const pi){
	if (n>0){
		draw_distance(2 * pi*radius(x) / 360);
		turn_right_by_degrees(1);
		line_and_turn(x, y, n - 1, pi);
	}
}

void circle_para(int const x, int const y, int const n, double const pi){
	move_to((x / 2.0), (y / 2.0) - radius(x));
	set_heading_degrees(90);
	set_pen_color(color::black);
	set_pen_width(3);
	line_and_turn(x, y, n, pi);
}

void sec_min_hour_ind(int const x, int const y, int const vari2){
	set_pen_width(4);
	set_pen_color(color::black);
	if (vari2 % 5 == 0 && vari2>0){
		move_to(x / 2.0, y / 2.0);
		move_distance(radius(x)*.90);
		draw_distance(radius(x)*.10);
		turn_right_by_degrees(6);
		sec_min_hour_ind(x, y, vari2 - 1);
	}
	else if (vari2>0){
		move_to(x / 2.0, y / 2.0);
		move_distance(radius(x)*.95);
		draw_distance(radius(x)*.05);
		turn_right_by_degrees(6);
		sec_min_hour_ind(x, y, vari2 - 1);
	}
}

void clock_hands_refresh(int const x, int const y, bool const timeON){            //include the displa of time and date in this function too -- make three serpeate if statemetns more
	set_pen_color(color::black);
	set_pen_width(2);
	int s = angle_of_second_hand();
	int j = angle_of_minute_hand();
	int k = angle_of_hour_hand();
	int t = fixed_second();
	int g = fixed_minute();
	int b = fixed_hour();
	move_to(x / 4.0, y / 8.0);
	write_string(b);
	write_string(":");
	write_string(g);
	write_string(":");
	write_string(t);
	if (1){
		move_to(x / 2.0, y / 2.0);
		set_heading_degrees(0);
		turn_right_by_degrees(s);
		draw_distance(second_hand_length(x));
		if (1){
			move_to(x / 2.0, y / 2.0);
			set_heading_degrees(0);
			turn_right_by_degrees(j);
			draw_distance(minute_hand_length(x));
			if (1){
				move_to(x / 2.0, y / 2.0);
				set_heading_degrees(0);
				turn_right_by_degrees(k);
				draw_distance(hour_hand_length(x));
				wait(.65);
				if (1){
					set_pen_width(5);
					set_heading_degrees(0);
					turn_right_by_degrees(s);
					set_pen_color(color::white);
					move_to(x / 2.0, y / 2.0);
					draw_distance(second_hand_length(x));
					if (1){
						set_heading_degrees(0);
						turn_right_by_degrees(j);
						move_to(x / 2.0, y / 2.0);
						draw_distance(minute_hand_length(x));
						if (1){
							set_heading_degrees(0);
							turn_right_by_degrees(k);
							move_to(x / 2.0, y / 2.0);
							draw_distance(hour_hand_length(x));
							clock_hands_refresh(x, y, timeON);

						}
					}
				}
			}
		}
	}
}

void main(){
	cout << "How many pixels wide would you like your clock window to be?" << " (Around 350 is a good pick)" << endl;
	int const x = read_int();
	int const y = 1.5 * x;
	//int const x = 300;                                                                   //defines window size in x direction
	//int const y = 600;                                                                   //degines window size in y direction
	int const n = 360;
	int const vari2 = 60;
	int const timeON = 10;
	double const pi = acos(-1.0);
	make_window(x, y);
	circle_para(x, y, n, pi);
	set_heading_degrees(0);
	sec_min_hour_ind(x, y, vari2);
	clock_hands_refresh(x, y, timeON);
}
