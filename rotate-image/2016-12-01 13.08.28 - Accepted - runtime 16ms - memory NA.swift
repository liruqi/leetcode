class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        let n = matrix.count
        var row = [Int](repeating: 0, count: n)
        var res = [[Int]](repeating: row, count: n)
        for x in 0..<n {
            for y in 0..<n {
                res[x][y] = matrix[n - 1 - y][x]
            }
        }
        matrix = res
    }
}