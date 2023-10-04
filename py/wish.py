import random

def generate_message(friend_name, achievement):
  messages = [
    f"Congratulations, {friend_name}! I'm so proud of you for achieving [achievement]. You deserve all the success in the world.",
    f"I know how hard you worked for [achievement], and I'm so happy to see your hard work pay off. Congratulations, {friend_name}!",
    f"{friend_name}, you're an inspiration to me and to everyone who knows you. Congratulations on your amazing achievement!",
    f"I'm so lucky to have you as a friend, {friend_name}. Congratulations on your well-deserved success!",
    f"Keep up the great work, {friend_name}! I can't wait to see what you accomplish next."
  ]

  message = random.choice(messages)
  message = message.replace("[achievement]", achievement)
  message = message.replace("{friend_name}", friend_name)
  return message

# Example usage:
friend_name = "Navneet"
achievement = "TTTTTT"

message = generate_message(friend_name, achievement)

print(message)
