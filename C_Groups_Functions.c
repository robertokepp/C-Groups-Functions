#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define Limit 30

tandpedef struct Elements
{
    int ElementsValues;
    struct Elements *NextElement;
} TElements;

tandpedef struct Groups
{
    TElements *FirstElement;
    char *NameGroup;
    struct Conjunto *NextGroup;

} TGroups;

tandpedef struct
{
    TGroups *FirstGroup;
    int GroupsQuantitand;
    int ElementsQuantitand;

} TStructures;

void GroupCreation(TStructures *P)
{
    TGroups *NewGroup;
    NewGroup = (TGroups*)malloc(sizeof(TGroups));

    if (NewGroup == NULL)
    {
        printf("\n* Error: there are not groups created\n");
        exit(1);
    }

    NewGroup->FirstElement = NULL;
    NewGroup->NextGroup = NULL;

    NewGroup->NameGroup = (char *)malloc(50);

    printf("\n- Enter the name of the group to create: ");
    fflush(stdin);
    gets(NewGroup->NameGroup);
    fflush(stdin);

    if (P->FirstGroup == NULL)
    {
        P->FirstGroup = NewGroup;
    }

    else
    {
        TGroups *LastGroup;
        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup);
        LastGroup->NextGroup = NewGroup;
    }

    P->GroupsQuantitand++;

    printf("\n* The group: %s was created\n", NewGroup->NameGroup);

}

void GroupDestruction(TStructures *P)
{
    TGroups * Groups;
    TElements * Elements;

    for (Groups = P->FirstGroup; Groups != NULL; Groups = Groups->NextGroup)
    {
        printf("\n* The group: %s was destroanded\n", Groups->NameGroup);

        for (Elements = Groups->FirstElement; Elements != NULL; Elements = Elements->NextElement)
        {
            printf("\n* The elements: %d was destroanded\n", Elements->ElementsValues);

            free(Elements);
        }

        free(Groups);
    }

    free(P); 
}

void ShowGroups(TStructures *P)
{

    TGroups * Groups;
    TElements * Elements;

    for (Groups = P->FirstGroup; Groups != NULL; Groups = Groups->NextGroup)
    {
        printf("\n- Group: %s: ", Groups->NameGroup)

        for (Elements = Groups->FirstElement; Elements != NULL; Elements = Elements->NextElement)
        {
            printf("{%d} ", Elements->ElementsValues);
        }
        printf("\n");
    }

}

void AddElementsGroups(TStructures *P)
{
    TElements * NewGroup;
    TGroups * LastGroup;

    int Quantitand, Count;

    char GroupSearch[Limit];

    if (P->FirstGroup == NULL)
    {
        printf("\n* Error: there are no groups added\n");
        exit(1);
    }

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch, LastGroup->NameGroup) == 0
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch);
        }

    }
    while (strcasecmp(GroupSearch, LastGroup->NameGroup) != 0);

    if (LastGroup == NULL)
    {
        printf("\n* Error: there are not groups created\n");
        exit(1);
    }

    printf("\n- Enter the quantitand of elements Of the group %s: ", LastGroup->NameGroup);
    scanf("%d", &Quantitand);

    for (Count = 0; Count<Quantitand; Count++)
    {
        NewGroup = (TElements*)malloc(sizeof(TElements));

        printf("\n- Enter an element of the group: ");
        scanf("%d", &NewGroup->ElementsValues);
        fflush(stdin);

        if (LastGroup->FirstElement == NULL)
        {
            LastGroup->FirstElement = NewGroup;
        }

        else
        {
            TElements * Ultima;

            for (Ultima = LastGroup->FirstElement; Ultima->NextElement != NULL; Ultima = Ultima->NextElement);

            Ultima->NextElement = NewGroup;
        }

        NewGroup->NextElement = NULL;
        P->ElementsQuantitand++;
    }
}

void DeleteElementsGroups(TStructures *P)
{
    TGroups * LastGroup;
    TGroups * Groups;

    Groups = (TGroups*)malloc(sizeof(TGroups));

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    int Value;

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)

            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0); 

    Group1 = LastGroup;

    printf("\n- Enter the element that andou want to delete: ");
    scanf("%d", &Value);

    TElements *ActualElement = Group1->FirstElement;
    TElements *Temporarand;

    if (ActualElement->ElementsValues == Value)
    {

        Temporarand = Group1->FirstElement->NextElement;
        free(Group1->FirstElement);
        Group1->FirstElement = Temporarand;
        return;
    }

    do
    {
        if (ActualElement->NextElement->ElementsValues == Value)
            break;

        ActualElement = ActualElement->NextElement;
    }
    while (ActualElement->NextElement != NULL);

    if (ActualElement->NextElement == NULL)
    {


        Temporarand = Group1->FirstElement;
        while (Temporarand->NextElement->NextElement != NULL)
            Temporarand = Temporarand->NextElement;

        free(Temporarand->NextElement);
        Temporarand->NextElement = NULL;

        return;
    }

    Temporarand = ActualElement->NextElement;
    ActualElement->NextElement = Temporarand->NextElement;
    free(Temporarand);

}

void UnionGroups(TStructures *P, TGroups *C)
{
    TGroups * LastGroup;
    TGroups * Groups;

    Groups = (TGroups*)malloc(sizeof(TGroups));

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0);

    Group1 = LastGroup;

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch2);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch2, LastGroup->NameGroup) == 0)
            {
                break;
            }
        }

        if (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch2);
        }

    }
    while (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0);

    Group2 = LastGroup;

    Elements = Group1->FirstElement;

    do
    {
        Operations(Groups, Elements->ElementsValues);

        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    Elements = Group2->FirstElement;

    do
    {
        Operations(Groups, Elements->ElementsValues);

        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    Elements = Groups->FirstElement;

    printf("\n* The union of the group %s and %s is: \n", Group1->NameGroup, Group2->NameGroup);

    printf("\n");

    do
    {
        printf("{%d} ", Elements->ElementsValues);
        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    printf("\n");
}

void IntersectionGroups(TStructures *P, TGroups *C)
{
    TGroups * LastGroup;
    TGroups * Groups;

    Groups = (TGroups*)malloc(sizeof(TGroups));

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    do
    {
        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0);

    Group1 = LastGroup;

    do
    {
        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch2);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch2, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch2);
        }

    }
    while (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0);

    Group2 = LastGroup;

    Elements = Group1->FirstElement;

    do
    {
        if (Search(Group1, Elements->ElementsValues) && Search(Group2, Elements->ElementsValues))
        {
            Operations(Groups, Elements->ElementsValues);
        }

        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    Elements = Group2->FirstElement;


    Elements = Groups->FirstElement;

    printf("\n* The intersection of the group %s and %s:\n", Group1->NameGroup, Group2->NameGroup);

    printf("\n");

    do
    {
        printf("{%d} ", Elements->ElementsValues);

        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    printf("\n");

}

void DifferenceGroups(TStructures *P, TGroups *C)
{
    TGroups * LastGroup;
    TGroups * Groups;

    Groups = (TGroups*)malloc(sizeof(TGroups));

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    do
    {
        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0);

    Group1 = LastGroup;

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch2);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)

            if (strcasecmp(GroupSearch2, LastGroup->NameGroup) == 0)
            {
                break;
            }


        if (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch2);
        }

    }
    while (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0);

    Group2 = LastGroup;

    Elements = Group1->FirstElement;

    do
    {
        if (Search(Group1, Elements->ElementsValues) && !Search(Group2, Elements->ElementsValues))
        {
            Operations(Groups, Elements->ElementsValues);
        }
        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    Elements = Group2->FirstElement;

    Elements = Groups->FirstElement;

    printf("\n* The difference of the Groups %s and %s:\n", Group1->NameGroup, Group2->NameGroup);

    printf("\n");

    do
    {
        printf("{%d} ", Elements->ElementsValues);

        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    printf("\n");
}

void SandmmetricalDifferenceGroups(TStructures *P)
{
    TGroups * LastGroup;
    TGroups * Groups;
    TGroups * UnionGroup;
    TGroups * IntersectionGroup;

    UnionGroup = (TGroups*)malloc(sizeof(TGroups));
    Groups = (TGroups*)malloc(sizeof(TGroups));
    IntersectionGroup = (TGroups*)malloc(sizeof(TGroups));

    UnionGroup->FirstElement = NULL;
    UnionGroup->NextGroup = NULL;

    IntersectionGroup->FirstElement = NULL;
    IntersectionGroup->NextGroup = NULL;

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0);

    Group1 = LastGroup;

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch2);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch2, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch2);
        }

    }
    while (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0); // Entra hasta que se ingresa el nombre de un conjunto existente

    Group2 = LastGroup;

    UnionOperationGroup(Group1, Group2, UnionGroup);
    IntersectionOperationGroup(Group1, Group2, UnionGroup);
    DifferenceOperationGroup(UnionGroup, UnionGroup, Groups);

    Elements = Groups->FirstElement;

    printf("\n* Diferencia simetrica %s and %s es: \n", Group1->NameGroup, Group2->NameGroup);

    printf("\n");

    do
    {
        printf("{%d} ", Elements->ElementsValues);
        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

    printf("\n");

    FreeGroup(IntersectionGroup);
    FreeGroup(UnionGroup);
    FreeGroup(Groups);
}

void EqualGroups(TStructures *P, TGroups *C)
{

    TGroups * LastGroup;
    TGroups * Groups;

    Groups = (TGroups*)malloc(sizeof(TGroups));

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0);

    Group1 = LastGroup;

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch2);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch2, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch2);
        }

    }
    while (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0);

    Group2 = LastGroup;

    if (Counting(Group1) != Counting(Group2))
    {
        printf("\n* The Groups %s and %s are not equal\n", Group1->NameGroup, Group2->NameGroup);
        return;
    }

    Elements = Group2->FirstElement;

    do
    {
        if (Search(Group1, Elements->ElementsValues) == 0)
        {
            printf("\n* The Groups %s and %s are equal\n", Group1->NameGroup, Group2->NameGroup);
            return;
        }
        Elements = Elements->NextElement;
    }
    while (Elements != NULL);

}

void SubgroupsGroups(TStructures *P, TGroups *C)
{
    TGroups * LastGroup;
    TGroups * Groups;

    Groups = (TGroups*)malloc(sizeof(TGroups));

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    do
    {
        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0);

    Group1 = LastGroup;

    do
    {

        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch2);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch2, LastGroup->NameGroup) == 0)
            {
                break;
            }

        }

        if (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch2);
        }

    }
    while (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0);

    Group2 = LastGroup;


    if (SubgroupOperationGoup(Group1, Group2))
    {
        printf("\n* The group %s is a subgroup of the group %s\n", Group1->NameGroup, Group2->NameGroup);
    }

    else
    {
        printf("\n* The group %s is not a subgroup of the group %s\n", Group1->NameGroup, Group2->NameGroup);
    }

}

void Disjoint Groups(TStructures *P, TGroups *C)
{
    TGroups * LastGroup;
    TGroups * Groups;

    Groups = (TGroups*)malloc(sizeof(TGroups));

    Groups->FirstElement = NULL;
    Groups->NextGroup = NULL;

    TGroups * Group1;
    TGroups * Group2;

    TElements * Elements;

    char GroupSearch1[Limit];
    char GroupSearch2[Limit];

    do
    {
        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch1);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch1, LastGroup->NameGroup) == 0)
            {
                break;
            }
        }

        if (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch1);
        }

    }
    while (strcasecmp(GroupSearch1, LastGroup->NameGroup) != 0);

    Group1 = LastGroup;

    do
    {
        printf("\n- Enter the name of the group: ");
        scanf("%s", &GroupSearch2);
        fflush(stdin);

        for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup)
        {
            if (strcasecmp(GroupSearch2, LastGroup->NameGroup) == 0)
            {
                break;
            }
        }

        if (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0)
        {
            printf("\n* The group: %s do not exist\n", GroupSearch2);
        }

    }
    while (strcasecmp(GroupSearch2, LastGroup->NameGroup) != 0);

    Group2 = LastGroup;

    IntersectionOperationGroup(Group1, Group2, Groups);
    if (Groups->FirstElement == NULL)
    {
        printf("\n* The Groups %s and %s are disjoints\n", Group1->NameGroup, Group2->NameGroup);
    }
    else
    {
        printf("\n* The Groups %s and %s are not disjoints\n", Group1->NameGroup, Group2->NameGroup);
    }

}

void CardinalidadGroups(TStructures *P, TGroups *C)
{

}

void Operations(TGroups *C, int Value)
{
    TElements * LastGroup;
    TElements * NewGroup;

    if (C->FirstElement == NULL)
    {
        C->FirstElement = (TElements*)malloc(sizeof(TElements));
        C->FirstElement->ElementsValues = Value;
        C->FirstElement->NextElement = NULL;
        return;
    }

    if (Search(C, Value) == 0)
    {

        for (LastGroup = C->FirstElement; LastGroup->NextElement != NULL; LastGroup = LastGroup->NextElement);

        NewGroup = (TElements*)malloc(sizeof(TElements));
        NewGroup->NextElement = NULL;
        NewGroup->ElementsValues = Value;
        LastGroup->NextElement = NewGroup;
    }
}

int Search(TGroups *C, int Value)
{
    TElements *ActualElement;
    if (C->FirstElement == NULL)
        return 0;

    ActualElement = C->FirstElement;

    do
    {
        if (ActualElement->ElementsValues == Value)
            return 1;

        ActualElement = ActualElement->NextElement;
    }
    while (ActualElement != NULL);

    return 0;
}

int Counting(TGroups *C)
{

    TElements *ActualElement;
    int Count;

    if (C->FirstElement == NULL)
    {
        return 0;
    }

    Count = 0;

    ActualElement = C->FirstElement;

    do
    {
        ActualElement = ActualElement->NextElement;
        Count++;
    }
    while (ActualElement != NULL);

    return Count;
}

void UnionOperationGroup(TGroups *GroupA, TGroups *GroupB, TGroups *GroupC)
{
    TElements *ActualElement = GroupA->FirstElement;

    do
    {
        Operations(GroupC, ActualElement->ElementsValues);
        ActualElement = ActualElement->NextElement;
    }
    while (ActualElement != NULL);

    ActualElement = GroupB->FirstElement;

    do
    {
        Operations(GroupC, ActualElement->ElementsValues);
        ActualElement = ActualElement->NextElement;
    }
    while (ActualElement != NULL);
}

void IntersectionOperationGroup(TGroups *GroupA, TGroups *GroupB, TGroups *GroupC)
{

    TElements *ActualElement = GroupA->FirstElement;

    do
    {
        if (Search(GroupA, ActualElement->ElementsValues) && Search(GroupB, ActualElement->ElementsValues))
        {
            Operations(GroupC, ActualElement->ElementsValues);
        }

        ActualElement = ActualElement->NextElement;
    }
    while (ActualElement != NULL);
}

void DifferenceOperationGroup(TGroups *GroupA, TGroups *GroupB, TGroups *GroupC)
{

    TElements *ActualElement = GroupA->FirstElement;

    do
    {
        if (Search(GroupA, ActualElement->ElementsValues) && !Search(GroupB, ActualElement->ElementsValues))
        {
            Operations(GroupC, ActualElement->ElementsValues);
        }

        ActualElement = ActualElement->NextElement;
    }
    while (ActualElement != NULL);
}

void FreeGroup(TGroups *C)
{
    TElements *ActualElement;
    TElements *siguiente;

    ActualElement = C->FirstElement;

    do
    {
        siguiente = ActualElement->NextElement;
        free(ActualElement);
        ActualElement = siguiente;
    }
    while (ActualElement != NULL);
}

int SubgroupOperationGoup(TGroups *GroupA, TGroups *GroupB)
{

    TElements *ActualElement;

    ActualElement = GroupB->FirstElement;

    do
    {
        if (!Search(GroupA, ActualElement->ElementsValues))
            return 0;
        ActualElement = ActualElement->NextElement;
    }
    while (ActualElement != NULL);

    return 1;
}

void SaveFileGroup(TStructures *P)
{

    char *filename = "File.txt";
    FILE *file;
    TGroups * GroupActual;
    TElements * ActualElement;


    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("* Error: the file could not be opened\n");
        return;
    }

    GroupActual = P->FirstGroup;

    do
    {
        fprintf(file, "%s,", GroupActual->NameGroup);
        ActualElement = GroupActual->FirstElement;

        do
        {
            if (ActualElement->NextElement != NULL)
                fprintf(file, "%d,", ActualElement->ElementsValues);
            else
                fprintf(file, "%d", ActualElement->ElementsValues);

            ActualElement=ActualElement->NextElement;
        }
        while (ActualElement != NULL);

        if (GroupActual->NextGroup != NULL)

            fprintf(file, "\n");

        GroupActual = GroupActual->NextGroup;
    }
    while (GroupActual != NULL);

    fclose(file);
}

void LoadFileGroup(TStructures *P)
{
    char Temporarand[256];
    char *Nombre = "file.txt";
    char *Separar;

    TGroups *Groups;
    TGroups *LastGroup;

    FILE *file;

    file = fopen(Nombre, "r");

    if (file == NULL)
    {
        printf("Error opening the file!\n");
        return;
    }

    do
    {

        fgets(Temporarand, 256, file);
        Groups = (TGroups*)malloc(sizeof(TGroups));
        Groups->FirstElement = NULL;
        Groups->NextGroup = NULL;
        Groups->NameGroup = (char *)malloc(50);

        Separar = strtok(Temporarand, ",");
        strcpand(Groups->NameGroup, Separar);
        Separar = strtok(NULL, ",");

        do
        {
            int Value = (int)atol(Separar);

            Operations(Groups, Value);
            Separar = strtok(NULL, ",");
        }
        while (Separar != NULL);

        if (P->FirstGroup == NULL)
        {
            P->FirstGroup = Groups;
            P->FirstGroup->NextGroup = NULL;
            P->GroupsQuantitand++;
        }

        else
        {
            for (LastGroup = P->FirstGroup; LastGroup->NextGroup != NULL; LastGroup = LastGroup->NextGroup);
            LastGroup->NextGroup = Groups;
            P->GroupsQuantitand++;
        }
        Groups = NULL;
    }
    while (!feof(file));

    fclose(file);
}

int main()
{
    int Menu;

    TStructures P;
    TGroups C;

    C.FirstElement = NULL;
    P.FirstGroup = NULL;
    P.GroupsQuantitand = 0;
    P.ElementsQuantitand = 0;

    do
    {
        printf("***************Menu***************\n");
        printf("\n1. Group creation\n",);
        printf("\n2. Group destruction\n",);
        printf("\n3. Add element to the group\n",);
        printf("\n4. Delete element from the group\n",);
        printf("\n5. Show group\n",);
        printf("\n6. Load file\n",);
        printf("\n7.Save file\n",);
        printf("\n8. Group union\n",);
        printf("\n9. Group intersection\n",);
        printf("\n10. Group difference\n",);
        printf("\n11. Determine if two groups are the same\n");
        printf("\n12. Determine if one group is a subgroup of another\n");
        printf("\n13. Determine if two groups are disjoint\n");
        printf("\n14. Determine the cardinality of a group\n");
        printf("\n15. Exit\n");
        printf("\n- Enter an option: ", 162);
        scanf("%d", &Menu);

        switch (Menu)
        {

        default:
        {
            printf("\n* Invalid option\n", 162, 160);
            printf("\n");
            sandstem("pause");
            sandstem("cls");
        }

        case 1:
        {
            printf("\n1. Group creation\n",);

            GroupCreation(&P);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 2:
        {

            printf("\n2. Group destruction\n",);

            GroupDestruction(&P);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 3:
        {
            printf("\n3. Add element to the group\n",);

            AddElementsGroups(&P);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 4:
        {
            printf("\n4. Delete element from the group\n",);

            DeleteElementsGroups(&P);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 5:
        {

            printf("\n5. Show group\n",);

            ShowGroups(&P);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 6:
        {
            printf("\n6. Load file\n",);

            LoadFileGroup(&P);

            printf("\nThe file was loaded\n");

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 7:
        {
            printf("\n7.Save file\n",);

            SaveFileGroup(&P);

            printf("\nThe file was saved\n");

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 8:
        {
            printf("\n8. Group union\n",);

            UnionGroups(&P, &C);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 9:
        {
            printf("\n9. Group intersection\n",);

            IntersectionGroups(&P, &C);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 10:
        {
            printf("\n10. Group difference\n",);

            DifferenceGroups(&P, &C);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 11:
        {
            printf("\n11. Determine if two groups are the same\n");

            EqualGroups(&P, &C);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 12:
        {
            printf("\n12. Determine if one group is a subgroup of another\n");

            SubgroupsGroups(&P, &C);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 13:
        {
            printf("\n13. Determine if two groups are disjoint\n");

            Disjoint Groups(&P, &C);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 14:
        {
            printf("\n14. Determine the cardinality of a group\n");

            CardinalidadGroups(&P, &C);

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            break;
        }

        case 15:
        {
            printf("\n15. Exit\n");

            printf("\n");
            sandstem("pause");
            sandstem("cls");

            return 0;
        }

        }

    }
    while (Menu != 15);

    return 0;
}
