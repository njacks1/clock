#include "library.h"

int hour(){
	return(get_clock_time() / 10000);
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

int minute(){
	return((get_clock_time() % 10000) / 100);
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

int year(){
  return(get_calendar_date()/10000);
}

int day(){
  return(get_calendar_date()%100);
}

int month(){
  return(((get_calendar_date()%10000)/100))
}

int month_array_value(){
  return(((get_calendar_date()%10000)/100)-1)
}

void date(){
  cout << "date: " << year() << "-" << month() << "-" << day();
}

void time(){
  cout << "time: " << fixed_hour() << ":" << fixed_minute();
}

void date_word(){
  cout << "month in words: " << monthab[month_array_value()];
}

void main(){
  string const monthab[11] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  date(); endl;
  time(); endl;
  date_word(monthab[11]);
}
