import random

class SnakesAndLadders:
    def __init__(self, board_size=100):
        self.board_size = board_size
        self.snakes = {
            16: 6, 48: 26, 64: 60, 79: 19, 92: 73, 95: 75, 98: 78
        }
        self.ladders = {
            2: 23, 6: 45, 20: 59, 52: 81, 57: 96, 71: 92, 88: 94
        }
        self.player_positions = [0, 0]
        self.player_turn = 0

    def move_player(self, player_id, dice_roll):
        new_position = self.player_positions[player_id] + dice_roll

        if new_position > self.board_size:
            return

        if new_position in self.snakes:
            new_position = self.snakes[new_position]
            print(f"Player {player_id + 1} hit a snake! Moved from {self.player_positions[player_id]} to {new_position}")
        elif new_position in self.ladders:
            new_position = self.ladders[new_position]
            print(f"Player {player_id + 1} hit a ladder! Moved from {self.player_positions[player_id]} to {new_position}")
        else:
            print(f"Player {player_id + 1} moved from {self.player_positions[player_id]} to {new_position}")

        self.player_positions[player_id] = new_position

    def is_game_over(self):
        for position in self.player_positions:
            if position >= self.board_size:
                winner = self.player_positions.index(position) + 1
                print(f"Player {winner} wins the game!")
                return True
        return False

    def play_game(self):
        while not self.is_game_over():
            player_id = self.player_turn % 2
            print(f"\nPlayer {player_id + 1}'s turn")
            dice_roll = self.roll_dice()
            self.move_player(player_id, dice_roll)
            self.player_turn += 1

    def roll_dice(self):
        while True:
            try:
                roll = int(input("Roll the dice (enter a number between 1 and 6): "))
                if 1 <= roll <= 6:
                    return roll
                else:
                    print("Invalid input. Please enter a number between 1 and 6.")
            except ValueError:
                print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    game = SnakesAndLadders()
    game.play_game()