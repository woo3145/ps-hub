

def recur (arr, idx, sum, target, answer):
    if len(arr) == idx:
        if(sum == target):
            answer[0] += 1
        return
    recur(arr, idx + 1, sum + arr[idx], target, answer)
    recur(arr, idx + 1, sum - arr[idx], target,answer)


def solution(numbers, target):
    answer = [0]
    recur(numbers, 0, 0, target, answer)
    return answer[0]