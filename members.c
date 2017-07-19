#include <stdio.h>
#include "members.h"

/* This file declares a linked list implementation to track and store members of units */

int isEmpty(memberNode* head)
{
    if (head->nextMember == NULL) {
        return 1;
    }
    return 0;
}

// create node with containing struct of unit member
memberNode* createNode(unitMember* unitStruct, memberNode* next)
{
    memberNode* newMember = (memberNode*)malloc(sizeof(memberNode));
    if (newMember == NULL) {
        printf("Failed to create node for new member.\n");
        exit(0);
    }
    newMember->member = unitStruct;
    newMember->nextMember = next;
    return newMember;
}

memberNode* prependMember(memberNode* head, unitMember* unitStruct)
{
    memberNode* newMember = createNode(unitStruct, head);
    head = newMember;
    return head;
}

memberNode* appendMember(memberNode* head, unitMember* unitStruct)
{
    memberUnit* cursor = head;
    while (cursor->nextMember != NULL) {
        cursor = cursor->nextMember;
    }

    memberNode* newMember = createNode(unitStruct, NULL);
    cursor->nextMember = newMember;

    return head;
}

memberNode* removeFront(memberNode* head)
{
    if (head == NULL) {
        return NULL;
    }

    memberNode* front = head;
    head = head->next;
    front->next = NULL;
    if (front == head) {
        head = NULL;
    }
    free(front);
    return head;
}

memberNode* removeBack(memberNode* head)
{
    if (head == NULL) {
        return NULL;
    }

    memberNode* cursor = head;
    memberNode* back = NULL;
    while (cursor->nextMember != NULL) {
        back = cursor;
        cursor = cursor->nextMember;
    }
    if (back != NULL) {
        back->nextMember = NULL;
    }
    if (cursor == head) {
        head == NULL;
    }

    free(cursor);
    return head;
}

memberNode* removeMember(memberNode* head, memberNode* memberToDelete) {
    if (memberToDelete == head) {
        head = removeFront(head);
        return head;
    }
    if (memberToDelete->nextMember == NULL) {
        head = removeBack(head);
        return head;
    }

    memberNode* cursor = head;
    while (cursor != NULL) {
        if (cursor->nextMember == memberToDelete) {
            break;
        }
        cursor = cursor->nextMember;
    }

    if (cursor != NULL) {
        memberNode* temp = cursor->nextMember;
        cursor->nextMember = temp->nextMember;
        temp->nextMember = NULL;
        free(temp);
    }

    return head;
}


memberNode* dispose(memberNode* head)
{
    memberNode* cursor;
    memberNode* temp;

    if (head != NULL) {
        cursor = head->nextMember;
        head->nextMember = NULL;
        while (cursor != NULL) {
            temp = cursor->nextMember;
            free(cursor;)
        }
    }
}
