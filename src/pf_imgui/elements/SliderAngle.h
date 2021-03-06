//
// Created by petr on 12/8/20.
//

#ifndef PF_IMGUI_IMGUI_ELEMENTS_SLIDERANGLE_H
#define PF_IMGUI_IMGUI_ELEMENTS_SLIDERANGLE_H

#include "ColorChooser.h"
#include "interface/LabeledElement.h"
#include "interface/SavableElement.h"
#include "interface/ValueObservableElement.h"
#include <pf_imgui/_export.h>
#include <string>

namespace pf::ui::ig {
class PF_IMGUI_EXPORT SliderAngle : public LabeledElement, public ValueObservableElement<float>, public SavableElement {
 public:
  SliderAngle(const std::string &elementName, const std::string &caption, float min, float max, float value = 0.0,
              Persistent persistent = Persistent::No, std::string format = "%.0f deg");

 protected:
  void renderImpl() override;
  void unserialize_impl(const toml::table &src) override;
  toml::table serialize_impl() override;

 private:
  float minDeg;
  float maxDeg;
  std::string format;
};
}// namespace pf::ui::ig

#endif//PF_IMGUI_IMGUI_ELEMENTS_SLIDERANGLE_H
