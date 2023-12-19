def can_play_card(table_card, hand_cards):
    table_rank, table_suit = table_card
    for hand_card in hand_cards:
        hand_rank, hand_suit = hand_card
        if hand_rank == table_rank or hand_suit == table_suit:
            return "YES"
    return "NO"

table_card = input().strip()
hand_cards = map(str, input().strip().split())

result = can_play_card(table_card, hand_cards)

print(result)
