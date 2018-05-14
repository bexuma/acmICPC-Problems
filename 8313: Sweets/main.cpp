//
//  main.cpp
//  8313: Sweets
//  URL: https://www.acmicpc.net/problem/8313
//
//  Created by Bexultan Myrzatayev on 5/4/18.
//  Copyright © 2018 Bexultan Myrzatayev. All rights reserved.
//

/* 
 * PROBLEM
 * To celebrate Children's Day a mother of three brothers - Anton, Dmytro and Borys - gave them loads of sweets. The treats are packed in n boxes, there are ai sweets in the i-th box. The brothers want to share the boxes justly. They agreed to the following rules:
 * an older brother cannot receive more sweets in total than a younger one (Anton is older than Dmytro, and Dmytro is older than Borys),
 * the difference between the total number of sweets given to Anton and the total number of sweets given to Borys should be minimal.ference between the total number of sweets given to Anton and the total number of sweets given to Borys should be minimal.

 * INPUT
 * In the first line of the standard input there is an integer n (3 ≤ n ≤ 24), denoting the number of boxes. The second line consists of n positive integers ai (1 ≤ ai ≤ 1,000,000,000), denoting the number of sweets in the boxes.
 
 * OUTPUT
 * In the only line of standard output you should write one integer - the difference between the numbers of sweets given to Anton and Borys.

*/


#include <iostream>

using namespace std;

const int number_of_brothers = 3;

int main() {
    int number_of_boxes;
    
    // VALIDATION (input): number of boxes
    bool validNumberOfBoxes = false;
    do {
        if (cin >> number_of_boxes && number_of_boxes >= 3 && number_of_boxes <= 24) { validNumberOfBoxes = true; }
        else { cout << "Error: Input must be more than 2, less than 25." << endl; }
    } while
        (!validNumberOfBoxes);
    
    // Creation an array of size n
    int* a = new int[number_of_boxes];
    
    // POPULATE array with elements
    for (int i = 0; i < number_of_boxes; i++) {
       
        // VALIDATION (input): number of candies in the box
        bool validNumberOfCandies = false;
        do {
            if (cin >> a[i] && a[i] >= 1 && a[i] <= 1000000000) { validNumberOfCandies = true; }
            else { cout << "Error: Input must be more than 0, less than billion and one." << endl; }
        } while
            (!validNumberOfCandies);
    }
    

    
    cout << "Input of n is " << number_of_boxes << endl;
    
    // TRAVERSE an array
    for (int i = 0; i < number_of_boxes; i++) {
        cout << a[i] << " sweets in the box #" << i + 1 << endl;
    }
    
    // SORT the array
    int temp;
    for (int i = 0; i < number_of_boxes - 1; i++) {
        for (int j = i + 1; j < number_of_boxes; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    // TRAVERSE an array (sorted)
    cout << "Array after sorting" << endl;
    for (int i = 0; i < number_of_boxes; i++) {
        cout << i + 1 << ": " <<  a[i] << endl;
    }
    
    
    // COMPUTE total number of candies
    int total_number_of_candies = 0;
    for (int i = 0; i < number_of_boxes; i++) {
        total_number_of_candies += a[i];
    }

    
    
    // PARTITION array into results array of size 3
    int threshold = (total_number_of_candies / number_of_brothers) - (total_number_of_candies / number_of_boxes) / 2;
    int* results = new int[number_of_brothers];
    int partSum = 0, partIndex = 0;

    for (int i = 0; i < number_of_boxes; i++) {
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
    
    for (int i = 0; i < number_of_brothers; i++) {
        cout << results[i] << endl;
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

    cout << results[0] << " sweets for Anton" << endl;
    cout << results[1] << " sweets for Dmytro" << endl;
    cout << results[2] << " sweets for Boris" << endl;
    
    cout << results[2] - results[0];
    
    
    return 0;
}
