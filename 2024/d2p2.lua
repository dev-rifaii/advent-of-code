local split_line = function(str)
    local tb = {}
    for match in string.gmatch(str, "(%S+)") do
        table.insert(tb, tonumber(match))
    end
    return tb
end

local total_safe_reports = 0

local is_safe_report = function(tokens)
    local incrementing = tokens[1] < tokens[2]
    for i = 1, #tokens - 1 do
        if incrementing ~= (tokens[i] < tokens[i + 1]) then return false end
        local diff = tokens[i] - tokens[i + 1]
        if diff < 0 then diff = diff * -1 end
        if diff < 1 or diff > 3 then return false end
    end

    return true
end

for line in io.lines("big.txt") do
    local tokens = split_line(line)
    local is_safe = is_safe_report(tokens)
    if is_safe then
        total_safe_reports = total_safe_reports + 1
    else
        for i = 1, #tokens do
            local new_tokens = split_line(line)
            table.remove(new_tokens, i)
            if is_safe_report(new_tokens) then
                total_safe_reports = total_safe_reports + 1
                break
            end
        end
    end
end

print(total_safe_reports)

