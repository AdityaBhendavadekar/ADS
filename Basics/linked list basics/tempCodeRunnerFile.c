 (pos > 0 && pos <= len + 1) {
        if (pos == 1) { // Inserting at the beginning
            newNode->next = *head;
            *head = newNode;
        } else {
            struct Node* temp = *head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        printf("Data inserted at position %d\n", pos);
    } else {
        printf("Element at position %d can't be inserted because linked list is of size %d\n", pos, len);
    }