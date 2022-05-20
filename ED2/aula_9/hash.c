#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ALGORITMOS HASHING --- Created on May 05 2022
 *  AUTHOR : Flavio Souza
 *  DESCRIPTION :
 *       Implementação de tabela Hash.
 */

#define SIZEHASH 50000

typedef struct item
{
    char *key;
    char *value;
} ITEM;

typedef struct hash
{
    ITEM **items;
    int size;
    int count;
} HASH;

HASH *init(int size)
{
    HASH *hash = (HASH *)malloc(sizeof(HASH));
    hash->size = size;
    hash->count = 0;
    hash->items = (ITEM **)calloc(hash->size, sizeof(ITEM *));
    for (int i = 0; i < hash->size; i++)
    {
        hash->items[i] = NULL;
    }

    return hash;
}

long hashFunction(char *key)
{
    long idx = 0;
    for (int i = 0; key[i]; i++)
    {
        idx += key[i];
    }
    ///printf("key:%s -> Index:%i\n", key, idx % SIZEHASH);
    return idx % SIZEHASH;
}

ITEM *createItem(char *key, char *value)
{
    ITEM *item = (ITEM *)malloc(sizeof(ITEM));
    item->key = (char *)malloc(strlen(key) + 1);
    item->value = (char *)malloc(strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

void put(HASH *hash, char *key, char *value)
{
    if (hash->count == hash->size)
    {
        printf("Hash esta cheia\n");
        return;
    }

    ITEM *item = createItem(key, value);
    int index = hashFunction(key);

    ITEM *current = hash->items[index];
    if (current == NULL)
    {
        hash->items[index] = item;
        hash->count++;
    }
}

void removeItem(HASH *hash, char *key)
{
    if (hash->count <= 0)
    {
        printf("Hash esta vazia\n");
        return;
    }

    int index = hashFunction(key);

    ITEM *current = hash->items[index];
    if (current != NULL)
    {
        free(hash->items[index]->key);
        free(hash->items[index]->value);
        free(hash->items[index]);
        hash->items[index] = NULL;
        hash->count--;
    }
}

char *search(HASH *hash, char *key)
{
    int index = hashFunction(key);
    ITEM *item = hash->items[index];

    if (item != NULL)
    {
        if (strcmp(item->key, key) == 0)
        {
            return item->value;
        }
    }
    return NULL;
}

void printHash(HASH *hash)
{
    printf("\n---- HASH (Size: %i; Count: %i)\n", hash->size, hash->count);
    for (int i = 0; i < hash->size; i++)
    {
        if (hash->items[i] != NULL)
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, hash->items[i]->key, hash->items[i]->value);
        }
    }
}

int main()
{
    HASH *hash = init(SIZEHASH);
    put(hash, "240.498.140-48", "Luis Emanuel Ramos");
    put(hash, "441.325.708-19", "Augusto Rafael Luis Ribeiro");
    put(hash, "721.602.703-50", "Mariana Fatima Raimunda da Rocha");
    put(hash, "318.092.947-20", "Agatha Flavia Luciana Vieira");
    put(hash, "516.792.976-86", "Betina Isis Costa");

    printHash(hash);
    removeItem(hash, "318.092.947-20");
    printHash(hash);

    char *value = search(hash, "721.602.703-50");
    printf("\nKey:%s, Value:%s\n", "721.602.703-50", value);
    value = search(hash, "240.498.140-48");
    printf("\nKey:%s, Value:%s\n", "240.498.140-48", value);

    return 0;
}