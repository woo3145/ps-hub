import sys

def calc_chance_costs(profit, costs):
    sorted_profit = sorted(profit, reverse=True)
    max_profit = sorted_profit[0]
    second_profit = sorted_profit[1]
    is_same = max_profit == second_profit
    arr = []
    for idx, cost in enumerate(costs):
        if profit[idx] == max_profit and not is_same:
            arr.append(second_profit - cost)
        else:
            arr.append(max_profit - cost)
    
    return arr

def calc_net_profit(profit, costs, chance_costs):
    arr = []
    for idx, c in enumerate(profit):
        arr.append(c - costs[idx] - chance_costs[idx])
    return arr

def solve():
    n = int(sys.stdin.readline().strip())
    profit = list(map(int, sys.stdin.readline().split()))
    costs = list(map(int, sys.stdin.readline().split()))
    
    chance_costs = calc_chance_costs(profit, costs)
    net_profit = calc_net_profit(profit, costs, chance_costs)
    print(" ".join(map(str, net_profit)))

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()