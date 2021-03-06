#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int** createTwoDimensionalArray(int height, int width, int defaultValue)
{
    int** distance = (int**) malloc(sizeof(int*) * height);

    for (int i = 0; i < height; i++)
    {
        distance[i] = (int*) malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
        {
            distance[i][j] = defaultValue;
        }
    }
    return distance;
}

int findNearestCity(const int* quantityOfCitiesInCountry, int** countries, int numberOfCapital,
                    int** distance, int quantityOfCities, const bool* used)
{
    int nearestCity = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < quantityOfCitiesInCountry[numberOfCapital]; i++)
    {
        int currentCity = countries[numberOfCapital][i];
        for (int j = 1; j <= quantityOfCities; j++)
        {
            if (distance[currentCity][j] < minDistance && !used[j])
            {
                nearestCity = j;
                minDistance = distance[currentCity][j];
            }
        }
    }

    return nearestCity;
}

void deleteTwoDimensionalArray(int** array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        free(array[i]);
    }
    free(array);
}

int** readDistances(const int quantityOfCities, const int quantityOfRoads, FILE* input, const int infinity)
{
    int** distance = createTwoDimensionalArray(quantityOfCities + 1, quantityOfCities + 1, infinity); //нумерация городов с 1

    int numberOfFirstCity = 0;
    int numberOfSecondCity = 0;
    int distanceBetweenCities = 0;
    for (int i = 0; i < quantityOfRoads; ++i)
    {
        fscanf(input, "%d %d %d", &numberOfFirstCity, &numberOfSecondCity, &distanceBetweenCities);
        distance[numberOfFirstCity][numberOfSecondCity] = distanceBetweenCities;
        distance[numberOfSecondCity][numberOfFirstCity] = distanceBetweenCities;
    }

    return distance;
}

void printCountries(int** countries, int quantityOfCapitals, const int* quantityOfCitiesInCountry)
{
    for (int i = 0; i < quantityOfCapitals; i++)
    {
        printf("%d county consists of cities: ", i + 1);
        for (int j = 0; j < quantityOfCitiesInCountry[i]; j++)
        {
            printf("%d ", countries[i][j]);
        }
        printf("\n");
    }
}

void assignCitiesToCountries(int quantityOfCapitals, int quantityOfCities, int** distance, bool* used,
                int** countries, int* quantityOfCitiesInCountry)
{
    int quantityOfAssignedCities = quantityOfCapitals;
    while (quantityOfAssignedCities < quantityOfCities)
    {
        for (int i = 0; i < quantityOfCapitals && quantityOfAssignedCities < quantityOfCities; ++i)
        {
            int numberOfNearestCity =
                    findNearestCity(quantityOfCitiesInCountry, countries, i, distance, quantityOfCities, used);
            if (numberOfNearestCity != -1)
            {
                used[numberOfNearestCity] = true;
                countries[i][quantityOfCitiesInCountry[i]] = numberOfNearestCity;
                quantityOfCitiesInCountry[i]++;
                quantityOfAssignedCities++;
            }
        }
    }
}

int main()
{
    const int infinity = INT_MAX;
    int quantityOfCities = 0;
    int quantityOfRoads = 0;
    FILE* input = fopen("input.txt", "r");
    if (!input)
    {
        printf("Error. Cannot open file.");
        return 0;
    }
    fscanf(input, "%d %d", &quantityOfCities, &quantityOfRoads);

    int** distance = readDistances(quantityOfCities, quantityOfRoads, input, infinity);

    int quantityOfCapitals = 0;
    fscanf(input, "%d", &quantityOfCapitals);

    int** countries = createTwoDimensionalArray(quantityOfCapitals, quantityOfCities - quantityOfCapitals, -1);
    int* quantityOfCitiesInCountry = (int*) malloc(sizeof(int) * quantityOfCapitals);
    bool* used = (bool*) calloc(quantityOfCities + 1, sizeof(bool)); // нумерация должна быть с 1
    for (int i = 0; i < quantityOfCapitals; ++i)
    {
        int currentCapital = 0;
        fscanf(input, "%d", &currentCapital); //нулевой столбец - список столиц
        countries[i][0] = currentCapital;
        used[currentCapital] = true;
        quantityOfCitiesInCountry[i] = 1;
    }

    assignCitiesToCountries(quantityOfCapitals, quantityOfCities, distance, used, countries, quantityOfCitiesInCountry);
    printCountries(countries, quantityOfCapitals, quantityOfCitiesInCountry);

    free(quantityOfCitiesInCountry);
    free(used);
    deleteTwoDimensionalArray(countries, quantityOfCapitals);
    deleteTwoDimensionalArray(distance, quantityOfCities + 1);
    fclose(input);
    return 0;
}