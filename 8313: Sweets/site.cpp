//
//  site.cpp
//  8313: Sweets
//
//  Created by Bexultan Myrzatayev on 5/4/18.
//  Copyright © 2018 Bexultan Myrzatayev. All rights reserved.
//


ICPC for Schools by CodeChef – This competition serves as a gateway for the school students to participate in ACM ICPC contest along with ICPC college participants held across India. It is an idea conceived by CodeChef and supported by Amrita University.

#include <iostream>

using namespace std;

const int number_of_brothers = 3;

int main() {
    int n;
    
    cin >> n;
    
    // Creation an array of size n
    int* a = new int[n];
    
    // POPULATE array with elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // SORT the array
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    // COMPUTE total number of candies
    int total_number_of_candies = 0;
    for (int i = 0; i < n; i++) {
        total_number_of_candies += a[i];
    }
    
    // PARTITION array into results array of size 3
    int threshold = (total_number_of_candies / number_of_brothers) - (total_number_of_candies / n) / 2;
    int* results = new int[number_of_brothers];
    int partSum = 0, partIndex = 0;
    
    for (int i = 0; i < n; i++) {
        partSum += a[i];
        
        if (partSum >= threshold) {
            results[partIndex] = partSum;
            partIndex++;
            partSum = 0;
        }
    }
    
    if (partIndex < number_of_brothers) {
        results[partIndex] = partSum;
    }
    
    // SORT the result array
    for (int i = 0; i < number_of_brothers - 1; i++) {
        for (int j = i + 1; j < number_of_brothers; j++) {
            if (results[i] > results[j]) {
                temp = results[i];
                results[i] = results[j];
                results[j] = temp;
            }
        }
    }
    
    cout << results[2] - results[0] << endl;
    
    return 0;
}

