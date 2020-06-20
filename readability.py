def get_letters(input):
    sent = 0
    wrds = 1
    let = 0
    i = 0

    while i < len(text):
        l = ord(text[i])

        # get words
        if l == 32:
            wrds += 1

        # get letters
        if l >= 65 and l <=90:
            let += 1
        elif l >= 97 and l <= 122:
            let += 1

        # get sentances
        if l == 33 or l == 46 or l == 63:
            sent += 1
        i += 1

    return(let, wrds, sent)


def reading_level(lets, words, sents):
    L = (lets/words)*100
    S = (sents/words) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index >= 16:
        return("Grade 16+")
    elif index < 1:
        return("Before Grade 1")
    else:
        return(f"Grade {index}")


text = str(input("Text: "))

letter_count, word_count, sent_count = get_letters(text)

answer = reading_level(letter_count, word_count, sent_count)

print(answer)
