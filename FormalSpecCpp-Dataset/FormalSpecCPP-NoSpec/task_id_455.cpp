bool MonthHas31Days(unsigned int month) {

    // Check if the month has 31 days
    bool result = (month == 1 || month == 3 || month == 5 || month == 7 ||
                   month == 8 || month == 10 || month == 12);


    return result;
}
