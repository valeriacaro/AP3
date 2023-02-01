#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> who_likes;
vector<int> pleased;
vector<int> songs;
int n, m, k;

void write(const vector<int>& v)
{
    if (v.size() > 0)
        cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        cout << "," << v[i];
    cout << endl;
}

// returns how many people could be pleased using the songs previously selected and all the songs starting at song song.
int max_pleased(int song, int n_of_pleased)
{
    vector<int> p;
    for (int i = song; i < n; ++i) {
        for (int j : who_likes[i]) {
            if (not pleased[j]) {
                pleased[j]++;
                p.push_back(j);
            }
        }
    }
    for (int j : p)
        pleased[j]--;
    return p.size() + n_of_pleased;
}
// k == current song
void compute_playlist(int song, int n_of_pleased)
{
    if (max_pleased(song, n_of_pleased) < m or songs.size() > k)
        return;
    if (song == n) {
        if (n_of_pleased == m)
            write(songs);
        return;
    }
    compute_playlist(song + 1, n_of_pleased);
    songs.push_back(song);
    for (int person : who_likes[song]) {
        if (pleased[person] == 0)
            n_of_pleased++;
        pleased[person]++;
    }
    compute_playlist(song + 1, n_of_pleased);
    songs.pop_back();
    for (int person : who_likes[song]) {
        if (pleased[person] == 1)
            n_of_pleased--;
        pleased[person]--;
    }
}

int main()
{
    cin >> n >> m;
    // row == song
    // column == person
    who_likes = vector<vector<int>>(n, vector<int>()); // who_likes[i] contains the persons who like the song i
    pleased = vector<int>(m, 0); // pleased[i] == # songs friend i likes.
    for (int person = 0; person < m; ++person) {
        int s;
        cin >> s;
        int song;
        for (int i = 0; i < s; ++i) {
            cin >> song;
            who_likes[song].push_back(person);
        }
    }
    cin >> k;
    compute_playlist(0, 0);
}
