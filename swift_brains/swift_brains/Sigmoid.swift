
import Darwin

class Sigmoid : Activation {
    private let e = 2.718
    
    public override func activate(x: Double) -> Double {
        return 1.0 / (1 + pow(e, -x))
    }
    
    public override func derivative(x: Double) -> Double {
        let a = activate(x: x)
        return a * (1 - a)
    }
}
