#include "../ModuleControls.hpp"

namespace kick {
class KickControls : public ModuleControls {
    public:
    KickControls(vector<Param>* p, vector<Output>* o, vector<Input>* i, vector<Light>* l, vector<ParamQuantity*>* pq) : ModuleControls {p, o, i, l, pq}
    {

    }
};
} //namespace Kick