#include "deck.h"

/**
* compare_cards - Main function to compare cards
* @a: Value a
* @b: Value b
* @Return: (always)
*/

int compare_cards(const void* a, const void* b) {
	const card_t* card1 = (*(deck_node_t**)a)->card;
	const card_t* card2 = (*(deck_node_t**)b)->card;

	if (card1->kind < card2->kind) {
		return -1;
	} else if (card1->kind > card2->kind) {
		return 1;
	} else {
		return strcmp(card1->value, card2->value);
	}
}

/**
* sort_deck - Main function that sorts decks
* @deck: The deck
* @Return: (null)
*/
void sort_deck(deck_node_t** deck) {
	int card_count = 0, i = 0, x = 0;
	deck_node_t* current = *deck;
	deck_node_t** deck_nodes_array;

	while (current) {
		card_count++;
		current = current->next;
	}

	deck_nodes_array = (deck_node_t**)malloc(sizeof(deck_node_t*) * card_count);

	current = *deck;
	for (; i < card_count; i++) {
		deck_nodes_array[i] = current;
		current = current->next;
	}

	qsort(deck_nodes_array, card_count, sizeof(deck_node_t*), compare_cards);

	*deck = deck_nodes_array[0];
	for (; x < card_count - 1; x++) {
		deck_nodes_array[x]->next = deck_nodes_array[x + 1];
		deck_nodes_array[x + 1]->prev = deck_nodes_array[x];
	}

	deck_nodes_array[card_count - 1]->next = NULL;
	free(deck_nodes_array);
}
