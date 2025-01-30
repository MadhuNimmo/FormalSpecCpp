// Function to calculate loss based on cost price and selling price
unsigned int CalculateLoss(unsigned int sellingPrice, unsigned int costPrice) {

    unsigned int loss;
    if (costPrice > sellingPrice) {
        loss = costPrice - sellingPrice;
    } else {
        loss = 0;
    }


    return loss;
}
