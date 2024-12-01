local left = {}
local right = {}

for line in io.lines "d1-data.txt" do
    local str = string.gsub(line, "%s+", ",")
    local sepIdx = str:find(",")
    local leftNumber = str:sub(0, sepIdx - 1)
    local rightNumber = str:sub(sepIdx + 1, #str)
    table.insert(left, leftNumber)
    right[rightNumber] = (right[rightNumber] or 0) + 1
end

local total = 0
for _, value in pairs(left) do
    local score = value * (right[value] or 0)
    total = total + score
end

print("\n" .. total)

