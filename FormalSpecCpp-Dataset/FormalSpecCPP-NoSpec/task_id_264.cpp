// Function to convert human years to dog years
unsigned int DogYears(unsigned int humanYears) {

    unsigned dogYears;

    // If the dog is 2 years or younger, each year is worth 10.5 dog years
    if (humanYears <= 2) {
        dogYears = humanYears * 10.5;
    } else {
        // First 2 years are 10.5 dog years each
        dogYears = 2 * 10.5;
        // Each additional year after that is worth 4 dog years
        dogYears += (humanYears - 2) * 4;
    }


    return dogYears;
}
