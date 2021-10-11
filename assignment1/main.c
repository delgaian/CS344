// If you are not compiling with the gcc option --std=gnu99, then
// uncomment the following line or you might get a compiler warning
//define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct for student information */
struct movies
{
    char *title;
    char *year;
    char *languages;
    char *ratingValue;
    int *choice;
    struct movies *next;
};

/* Parse the current line which is space delimited and create a
*   struct with the data in this line
*/
struct movies *createMovie(char *currLine)
{
    struct movies *currMovie = malloc(sizeof(struct movies));

    // For use with strtok_r
    char *saveptr;

    // The first token is the title
    char *token = strtok_r(currLine, " ", &saveptr);
    currMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->title, token);

    // The next token is the year
    token = strtok_r(NULL, " ", &saveptr);
    currMovie->year = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->year, token);

    // The next token is the languages
    token = strtok_r(NULL, " ", &saveptr);
    currMovie->languages = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->languages, token);

    // The last token is the ratingValue
    token = strtok_r(NULL, "\n", &saveptr);
    currMovie->ratingValue = calloc(strlen(token) + 1, sizeof(double));
    strcpy(currMovie->ratingValue, token);

    // Set the next node to NULL in the newly created student entry
    currMovie->next = NULL;

    return currMovie;
}

/*
* Return a linked list of movies by parsing data from
* each line of the specified file.
*/
struct movies *processFile(char *filePath)
{
    // Open the specified file for reading only
    FILE *movieFile = fopen(filePath, "r");

    char *currLine = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;

    // The head of the linked list
    struct movies *head = NULL;
    // The tail of the linked list
    struct movies *tail = NULL;

    // Read the file line by line
    while ((nread = getline(&currLine, &len, movieFile)) != -1)
    {
        // Get a new movie node corresponding to the current line
        struct movies *newNode = createMovie(currLine);

        // Is this the first node in the linked list?
        if (head == NULL)
        {
            // This is the first node in the linked link
            // Set the head and the tail to this node
            head = newNode;
            tail = newNode;
        }
        else
        {
            // This is not the first node.
            // Add this node to the list and advance the tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    free(currLine);
    fclose(movieFile);
    return head;
}

//create a menu for the user to choose an option of what to print out
void menus() {
    int* choice;
    printf("\nplease enter a number from 1-4 to choose an option below.\n");
    printf(" 1. Show movies released on a specified year.\n 2. Show highest rated movie by year\n 3. Show movie and year of released for a specific language.\n 4. Exit\n ");
    printf("please choose an option:\n");
    scanf("%d", &choice);

}


/*
* Print data for the given movie
*/
void printMovies(struct movies* aMovie){
  printf("%s, %s %s, %s\n", aMovie->title,
               aMovie->year,
               aMovie->languages,
               aMovie->ratingValue);
}
/*
* Print the linked list of movies
*/

void printMoviesByYear(struct movies* aMovie) {
    printf("%s, %s\n", aMovie->title, aMovie->year);
}

void printMoviesByRate(struct movies* aMovie) {
    prinf("%s, %s")
}
