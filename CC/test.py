def get_unique_strings(input_list):
    # Dictionary to store last occurrence of each string (case-insensitive key)
    seen = {}
    
    # Iterate through the input list
    for item in input_list:
        # Only process strings containing at least one letter
        if any(c.isalpha() for c in item):
            key = item.lower()
            seen[key] = item
    
    # Return the values (original case) sorted alphabetically (case-insensitive)
    return sorted(seen.values(), key=str.lower)

# Get user input
print("Enter strings (one per line, press Enter twice to finish):")
input_list = []
while True:
    line = input()
    if line == "":  # Stop when an empty line is entered
        break
    input_list.append(line)

# Get unique strings
result = get_unique_strings(input_list)

# Print output
for item in result:
    print(item)