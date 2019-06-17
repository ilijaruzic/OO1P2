#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct time {
    int hours, minutes;
} Time;

typedef struct patient {
    char firstName[21], lastName[21];
    int severity;
    Time sanitationTime;
} Patient;

typedef struct node {
    Patient patient;
    struct node *next;
} Node;

Node *readPatients() {
    Node *head = NULL, *tail = NULL;
    Patient patient;
    FILE *in = fopen("patients.txt", "r");
    if (in == NULL)
        exit(1);

    while (fscanf(in, "%s %s %d %d:%d\n", patient.firstName, patient.lastName, &patient.severity, &patient.sanitationTime.hours, &patient.sanitationTime.minutes) == 5) {
        Node *new = (Node *) malloc(sizeof(Node));
        if (new == NULL) 
            exit(1);
        
        new->patient = patient;
        new->next = NULL;
        
        if (head == NULL)
            head = new;
        else
            tail->next = new;
        tail = new;
    }

    fclose(in);

    return head;
}

int compare(Patient patient1, Patient patient2) {
    if (patient1.severity < patient2.severity)
        return -1;
    else if (patient1.severity > patient2.severity)
        return 1;
    else {
        int time1 = patient1.sanitationTime.hours * 60 + patient1.sanitationTime.minutes;
        int time2 = patient2.sanitationTime.hours * 60 + patient2.sanitationTime.minutes;

        if (time1 > time2)
            return -1;
        else if (time1 < time2) 
            return 1;
        else
            return 0;
    }
}

void sortPatients(Node *head) {
    for (Node *i = head; i != NULL; i = i->next)
        for (Node *j = i->next; j != NULL; j = j->next)
            if (compare(i->patient, j->patient) < 0) {
                Patient temp = i->patient;
                i->patient = j->patient;
                j->patient = temp;
            }
}

void matchAndWrite(Node *head, Time startTime, Time endTime) {
    FILE *out = fopen("schedule.txt", "w");
    if (out == NULL)
        exit(1);

    int start = startTime.hours * 60 + startTime.minutes;
    int end = endTime.hours * 60 + endTime.minutes;
    int first = 1;

    for (Node *i = head; i != NULL; i = i->next) {
        Patient patient = i->patient;
        int time = patient.sanitationTime.hours * 60 + patient.sanitationTime.minutes;
        if (time <= (end - start)) {
            int startExaminationTime = start;
            int endExaminationTime = start + time;
            int startExaminationTimeHours = startExaminationTime / 60;
            int startExaminationTimeMinutes = startExaminationTime % 60;
            int endExaminationTimeHours = endExaminationTime / 60;
            int endExaminationTimeMinutes = endExaminationTime % 60;
            
            start += time;
            fprintf(out, "%s %s %02d:%02d-%02d:%02d\n", patient.firstName, patient.lastName, startExaminationTimeHours, startExaminationTimeMinutes, endExaminationTimeHours, endExaminationTimeMinutes);
        }
    }

    fclose(out);
}

void deallocateList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        Node *old = current;
        current = current->next;
        free(old);
    }
}

int main() {
    Node *head = readPatients();
    sortPatients(head);

    Time startTime, endTime;
    printf("Doctor's working hours? [hh:mm-hh:mm]\n");
    scanf("%d:%d-%d:%d", &startTime.hours, &startTime.minutes, &endTime.hours, &endTime.minutes);
    matchAndWrite(head, startTime, endTime);

    deallocateList(head);

    return 0;
}