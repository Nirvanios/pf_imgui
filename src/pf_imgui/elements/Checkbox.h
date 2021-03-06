//
// Created by petr on 10/31/20.
//

#ifndef PF_IMGUI_ELEMENTS_CHECKBOX_H
#define PF_IMGUI_ELEMENTS_CHECKBOX_H

#include "interface/LabeledElement.h"
#include "interface/SavableElement.h"
#include "interface/ValueObservableElement.h"
#include <pf_imgui/_export.h>
#include <string>

namespace pf::ui::ig {
class PF_IMGUI_EXPORT Checkbox : public ValueObservableElement<bool>, public LabeledElement, public SavableElement {
 public:
  Checkbox(const std::string &elementName, const std::string &caption, Persistent persistent = Persistent::No,
           bool value = false);

  void setSelected(bool value);

  [[nodiscard]] bool isSelected() const;

 protected:
  void unserialize_impl(const toml::table &src) override;
  toml::table serialize_impl() override;

 protected:
  void renderImpl() override;
};

}// namespace pf::ui::ig
#endif//PF_IMGUI_ELEMENTS_CHECKBOX_H
