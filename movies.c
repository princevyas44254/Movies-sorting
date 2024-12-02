#include <stdio.h>
#include <string.h>

// Structure to store movie details
typedef struct {
    int movieID;
    char title[50];
    char genre[30];
    float rating;
} Movie;

// Function to sort movies by ratings
void sortMoviesByRating(Movie movies[], int count) {
    Movie temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            // Sort by rating in descending order; break ties with movie ID
            if (movies[i].rating < movies[j].rating || 
                (movies[i].rating == movies[j].rating && movies[i].movieID > movies[j].movieID)) {
                temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

// Function to display movie details
void displayMovies(Movie movies[], int count) {
    printf("\nMovie Ratings (Sorted by Rating):\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Movie ID: %d, Title: %s, Genre: %s, Rating: %.1f/10\n", 
               movies[i].movieID, movies[i].title, movies[i].genre, movies[i].rating);
    }
}

int main() {
    int count;
    printf("Enter the number of movies: ");
    scanf("%d", &count);

    Movie movies[count];

    // User inputs movie details
    for (int i = 0; i < count; i++) {
        printf("\nEnter details for movie %d:\n", i + 1);
        printf("Movie ID: ");
        scanf("%d", &movies[i].movieID);
        printf("Title: ");
        scanf(" %[^\n]", movies[i].title); // Using " %[^\n]" to read strings with spaces
        printf("Genre: ");
        scanf(" %[^\n]", movies[i].genre);
        printf("Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
    }

    // Sort movies by ratings
    sortMoviesByRating(movies, count);

    // Display sorted movie details
    displayMovies(movies, count);

    return 0;
}
