#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define NUM_STATIONS 26

void displayPath(int parent[], int dest, const char *stations[]) {
    if (parent[dest] == -1) {
        printf("No path available to reach destination.\n");
        return;
    }

    printf("Shortest path to %s:\n", stations[dest]);
    int path[NUM_STATIONS], count = 0;
    while (dest != -1) {
        path[count++] = dest;
        dest = parent[dest];
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%s -> ", stations[path[i]]);
    }
}

int minDistance(int dist[], bool visit[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < NUM_STATIONS; v++)
        if (visit[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[NUM_STATIONS][NUM_STATIONS], int src, int dest, const char *stations[]) {
    int dist[NUM_STATIONS];
    bool visit[NUM_STATIONS];
    int parent[NUM_STATIONS];

    for (int i = 0; i < NUM_STATIONS; i++) {
        dist[i] = INT_MAX;
        visit[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < NUM_STATIONS - 1; count++) {
        int u = minDistance(dist, visit);
        visit[u] = true;

        for (int v = 0; v < NUM_STATIONS; v++)
            if (!visit[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    displayPath(parent, dest, stations);
}

int findStationIndex(const char *station, const char *stations[]) {
    for (int i = 0; i < NUM_STATIONS; ++i) {
        if (strcmp(station, stations[i]) == 0) {
            return i;
        }
    }
    return -1;
}

   int main() {
    int metroGraph[NUM_STATIONS][NUM_STATIONS] = {

        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    const char *stationNames[NUM_STATIONS] = {
        "Anand Nagar", "Bopodi", "Bund Garden",
        "Chhatrapati Sambhaji Udyan", "Civil Court",
        "Dapodi", "Deccan Gymkhana", "Garware College",
        "Ideal Colony", "Kalyani Nagar",
        "Kasarwadi", "Khadki", "Mangalwar Peth",
        "Nal Stop", "Nashik Phata", "PCMC Bhavan",
        "Phugewadi", "PMC Bhavan", "Pune Railway Station",
        "Ramwadi", "Range Hills", "Ruby Hall Clinic", "Sant Tukaram Nagar",
        "Shivaji Nagar", "Vanaz", "Yerwada"
    };

    char source[100], destination[100];

    printf("===WELCOME TO PUNE METRO===\n");
      printf("\nList of metro stations:\n");
    for (int i = 0; i < NUM_STATIONS; i++) {
        printf("%d. %s\n", i + 1, stationNames[i]);
    }

    printf("\nEnter source metro station: ");

    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0;

    printf("Enter destination metro station: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0;

    int srcIndex = findStationIndex(source, stationNames);
    int destIndex = findStationIndex(destination, stationNames);

    if (srcIndex == -1) {
        printf("Invalid source station.\n");
        return 0;
    }

    if (destIndex == -1) {
        printf("Invalid destination station.\n");
        return 0;
    }

    if (srcIndex == destIndex) {
        printf("Source and destination stations are the same.\n");
        return 0;
    }

    dijkstra(metroGraph, srcIndex, destIndex, stationNames);

    return 0;
}