local splitLine = function(str)
    local tb = {}
    for match in string.gmatch(str, "(%S+)") do
        table.insert(tb, tonumber(match))
    end
    return tb
end

local totalSafeReports = 0

for line in io.lines("d2-input.txt") do
    local lineTokens = splitLine(line)
    local inc = true
    local isSafe = true
    if lineTokens[1] > lineTokens[2] then inc = false end
    for i = 2, #lineTokens do
        local isCurrInc = lineTokens[i] > lineTokens[i - 1]
        if (inc ~= isCurrInc) then isSafe = false break end
        local sum = lineTokens[i] - lineTokens[i -1]
        if (sum < 0) then sum = sum * -1 end
        if (sum < 1 or sum > 3) then isSafe = false break end
    end
    if isSafe then totalSafeReports = totalSafeReports + 1 end
end

print(totalSafeReports)
