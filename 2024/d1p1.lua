local leftList = {}
local rightList = {}

for line in io.lines "d1-input.txt" do
    local str = string.gsub(line, "%s+", ",")
    local sepIdx = str:find(",")
    table.insert(leftList, str:sub(0, sepIdx - 1))
    table.insert(rightList, str:sub(sepIdx + 1, #str))
end

local sortPredicate = function(a, b) return a < b end
table.sort(leftList, sortPredicate)
table.sort(rightList, sortPredicate)

local totalDistance = 0

for index, value in ipairs(leftList) do
    local distance = value - rightList[index];
    if (distance < 0) then distance = distance * -1 end
    totalDistance = totalDistance + distance;
end

print(totalDistance)
