//
// Created by petr on 10/31/20.
//

#ifndef PF_IMGUI_IMGUI_ELEMENTS_INTERFACE_CONTAINER_H
#define PF_IMGUI_IMGUI_ELEMENTS_INTERFACE_CONTAINER_H

#include "Element.h"
#include <unordered_map>
#include <memory>
#include <pf_common/exceptions/StackTraceException.h>
#include <pf_imgui/_export.h>
#include <string>

namespace pf::ui::ig {

class PF_IMGUI_EXPORT Container : public virtual Element {
 public:
  explicit Container(const std::string &elementName);
  template<typename T, typename... Args>
  requires std::derived_from<T, Element> &&std::constructible_from<T, std::string, Args...>
      std::shared_ptr<T> createChild(std::string name, Args &&... args) {
    auto child = std::make_shared<T>(name, std::forward<Args>(args)...);
    addChild(child);
    return child;
  }
  void addChild(std::shared_ptr<Element> child);
  void removeChild(const std::string &name);

  void enqueueChildRemoval(const std::string &name);

  template<std::derived_from<Element> T>
  [[nodiscard]] std::shared_ptr<T> childByName(const std::string &name) {
    if (const auto iter = children.find(name); iter != children.end()) {
      if (auto result = std::dynamic_pointer_cast<T>(iter->second); result != nullptr) {
        return result;
      }
      throw StackTraceException::fmt("Wrong type for child: '{}' in '{}'", name, getName());
    }
    throw StackTraceException::fmt("Child not found: '{}' in '{}'", name, getName());
  }

  [[nodiscard]] const std::vector<std::reference_wrapper<Element>> &getChildren();

  void clear();

 private:
  std::unordered_map<std::string, std::shared_ptr<Element>> children;
  std::vector<std::reference_wrapper<Element>> childrenInOrder;
  std::vector<std::string> childrenToRemove;
};

}// namespace pf::ui::ig
#endif//PF_IMGUI_IMGUI_ELEMENTS_INTERFACE_CONTAINER_H
