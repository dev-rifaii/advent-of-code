io.input("d3-input.txt")

mul = function(x, y) return x * y end

local sum = 0

for k,v in io.read("a"):gmatch("%mul%(%d+%,%d+%)") do
    local mul_result = load('return ' .. k)()
    sum = sum + mul_result
end

print(sum)
