class Solution {
public:
    // Custom structure to store meeting info
    struct Meeting {
        int start;
        int end;
    };

    // Comparator function to sort meetings by end time
    static bool compare(Meeting m1, Meeting m2) {
        return m1.end < m2.end;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Meeting> meetings(n);

        // Fill the meeting vector
        for (int i = 0; i < n; i++) {
            meetings[i].start = start[i];
            meetings[i].end = end[i];
        }

        // Sort meetings by end time using custom comparator
        sort(meetings.begin(), meetings.end(), compare);

        int count = 1; // At least one meeting can be selected
        int lastEnd = meetings[0].end;

        for (int i = 1; i < n; i++) {
            if (meetings[i].start > lastEnd) {
                count++;
                lastEnd = meetings[i].end;
            }
        }

        return count;
    }
};
