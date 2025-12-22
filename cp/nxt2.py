def averageTopFive(scores):
    student_scores = {}
    for sid, sc in scores:
        if sid not in student_scores:
            student_scores[sid] = []
        student_scores[sid].append(sc)

    result = []

    for sid in student_scores:
        scs = sorted(student_scores[sid], reverse=True)
        top_five = scs[:5]
        avg = sum(top_five) // len(top_five)
        result.append([sid, avg])

    result.sort(key=lambda x: x[0])
    return result


scores = [
    [101,85],[101,82],[102,90],[102,86],
    [101,90],[102,92],[101,91],[102,94],
    [101,60],[101,87],[102,88]
]

print(averageTopFive(scores))
