// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vformulafsm.h"
#include "Vformulafsm__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vformulafsm::Vformulafsm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vformulafsm__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vformulafsm::Vformulafsm(const char* _vcname__)
    : Vformulafsm(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vformulafsm::~Vformulafsm() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vformulafsm___024root___eval_initial(Vformulafsm___024root* vlSelf);
void Vformulafsm___024root___eval_settle(Vformulafsm___024root* vlSelf);
void Vformulafsm___024root___eval(Vformulafsm___024root* vlSelf);
#ifdef VL_DEBUG
void Vformulafsm___024root___eval_debug_assertions(Vformulafsm___024root* vlSelf);
#endif  // VL_DEBUG
void Vformulafsm___024root___final(Vformulafsm___024root* vlSelf);

static void _eval_initial_loop(Vformulafsm__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vformulafsm___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vformulafsm___024root___eval_settle(&(vlSymsp->TOP));
        Vformulafsm___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vformulafsm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vformulafsm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vformulafsm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vformulafsm___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vformulafsm::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vformulafsm::final() {
    Vformulafsm___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vformulafsm::hierName() const { return vlSymsp->name(); }
const char* Vformulafsm::modelName() const { return "Vformulafsm"; }
unsigned Vformulafsm::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vformulafsm::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vformulafsm___024root__trace_init_top(Vformulafsm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vformulafsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vformulafsm___024root*>(voidSelf);
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vformulafsm___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vformulafsm___024root__trace_register(Vformulafsm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vformulafsm::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vformulafsm::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vformulafsm___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
