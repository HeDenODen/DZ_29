#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct VideoStore 
{
    char title[100];
    char director[100];
    char genre[100];
    float rating;
    float price;
};

void AddFilm(VideoStore s[])
{
    char c;
    for (int i = 0; s[i].title; i++) {
        if (strlen(s[i].title) == 0) {
            cout << "Enter movie title: ";
            scanf("%*c");
            cin.getline(s[i].title, 100, '\n');
            cout << "Enter direcror's name: ";
            scanf("%*c");
            cin.getline(s[i].director, 100, '\n');
            cout << "Enter the movie genre: ";
            scanf("%*c");
            cin.getline(s[i].genre, 100, '\n');
            cout << "Enter movie rating: ";
            cin >> s[i].rating;
            cout << "Enter the price of the movie: ";
            cin >> s[i].price;
            cout << "Continue (y - yes, n - no): ";
            cin >> c;
            if (c == 'n' || c == 'N')
                break;
        }
    }
}
void ShowAllFilms(VideoStore alls[])
{
    for (int i = 0; alls[i].title; i++) {
        if (strlen(alls[i].title) != 0) {
            cout << "Movie title: " << alls[i].title << endl;
            cout << "Direcror's name: " << alls[i].director << endl;
            cout << "Movie rating: " << alls[i].rating << endl;
            cout << "Movie genre: " << alls[i].genre << endl;
            cout << "Price of the movie: " << alls[i].price << endl;
        }
    }
}
void MostPopularFilm(VideoStore m[], char g[])
{
    float max = m[0].price;
    int maxi = 0;
    for (int i = 0; m[i].title; i++)
        if (strlen(m[i].title) != 0)
            if (m[i].genre == g)
                if (max > m[i].rating) {
                    max = m[i].rating;
                    maxi = i;
                }
    cout << "Most popular by genre:\n";
    cout << "Movie title: " << m[maxi].title << endl;
    cout << "Direcror's name: " << m[maxi].director << endl;
    cout << "Movie rating: " << m[maxi].rating << endl;
    cout << "Movie genre: " << m[maxi].genre << endl;
    cout << "Price of the movie: " << m[maxi].price << endl;
}
void SearchFilmByName(VideoStore t[], char tit[])
{
    int c = 0;
    for (int i = 0; t[i].title; i++)
        if (strlen(t[i].title) != 0)
            if (strcmp(t[i].title, tit) == 0) {
                cout << "Movie title: " << t[i].title << endl;
                cout << "Direcror's name: " << t[i].director << endl;
                cout << "Movie rating: " << t[i].rating << endl;
                cout << "Movie genre: " << t[i].genre << endl;
                cout << "Price of the movie: " << t[i].price << endl;
                c++;
            }
        if(c == 0)
            cout << "Nothing found!" << endl;
}
void SearchFilmByGenre(VideoStore g[], char genr[])
{
    int c = 0;
    for (int i = 0; g[i].title; i++)
        if (strlen(g[i].title) != 0)
            if (strcmp(g[i].title, genr) == 0) {
                cout << "Movie title: " << g[i].title << endl;
                cout << "Direcror's name: " << g[i].director << endl;
                cout << "Movie rating: " << g[i].rating << endl;
                cout << "Movie genre: " << g[i].genre << endl;
                cout << "Price of the movie: " << g[i].price << endl;
                c++;
            }
    if (c == 0)
        cout << "Nothing found!" << endl;
}
void SearchFilmByDirector(VideoStore d[], char dir[])
{
    int c = 0;
    for (int i = 0; d[i].title; i++)
        if (strlen(d[i].title) != 0)
            if (strcmp(d[i].title, dir) == 0) {
                cout << "Movie title: " << d[i].title << endl;
                cout << "Direcror's name: " << d[i].director << endl;
                cout << "Movie rating: " << d[i].rating << endl;
                cout << "Movie genre: " << d[i].genre << endl;
                cout << "Price of the movie: " << d[i].price << endl;
                c++;
            }
    if (c == 0)
        cout << "Nothing found!" << endl;
}
int main()
{
    const int size = 100;
    VideoStore shop[size] = {};
    enum Action { SearchByName = 1, SearchByGenre, SearchByDirector, MostPopular, ShowAll, AddNew, Exit };
    char gen[100];
    char name[100], ge[100], direct[100];
    int UserChoice;
    do {
        cout << "Your choice:\n";
        cout << "1 - Search by name\n";
        cout << "2 - Search by genre\n";
        cout << "3 - Search by director\n";
        cout << "4 - Most popular by genre\n";
        cout << "5 - Show all films\n";
        cout << "6 - Add new film\n";
        cout << "7 - exit\n";
        cin >> UserChoice;
        switch (UserChoice)
        {
        case SearchByName:            
            cout << "Enter title: ";
            scanf("%*c");
            cin.getline(name, 100, '\n');
            SearchFilmByName(shop, name);
            break;
        case SearchByGenre:
            cout << "Enter genre: ";
            scanf("%*c");
            cin.getline(ge, 100, '\n');
            SearchFilmByGenre(shop, ge);
            break;
        case SearchByDirector:
            cout << "Enter director: ";
            scanf("%*c");
            cin.getline(direct, 100, '\n');
            SearchFilmByDirector(shop, direct);
            break;
        case MostPopular:
            cout << "Enter genre: ";
            scanf("%*c");
            cin.getline(gen, 100, '\n');
            MostPopularFilm(shop, gen);
            break;
        case ShowAll:
            ShowAllFilms(shop);
            break;
        case AddNew:
            AddFilm(shop);
            break;
        case Exit:
            cout << "See you!" << endl;
            break;        
        default:        
            cout << "Invalid command!" << endl;
            break;        
        }
    } while (UserChoice != 7);
    return 0;
}
