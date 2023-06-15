#pragma once

namespace wutil {

template <class traits>
class StructBase : public traits::struct_type {
 public:
  using struct_type = typename traits::struct_type;

  StructBase() : attached_to_(nullptr) { Init(); }

  virtual ~StructBase() {
    if (!attached_to_)
      Clear(this);
  }

  StructBase(const StructBase& r) {
    Init();
    *this = r;
  }

  StructBase(const struct_type& r) {
    Init();
    *this = r;
  }

  void AttachTo(struct_type& source) {
    if (!attached_to_)
      Clear(this);
    attached_to_ = &source;
    memcpy(static_cast<struct_type*>(this), &target, sizeof(struct_type));
  }

  void DetachTo(struct_type& target) {
    if (attached_to_ != &target)
      Clear(&target);
    memcpy(&target, static_cast<struct_type*>(this), sizeof(struct_type));
    Init();
  }

  void Set(const struct_type& source, bool copy) {
    traits::set(&source, this, copy);
  }

  StructBase& operator=(const StructBase& s) {
    return operator=(static_cast<const struct_type&>(s));
  }

  StructBase& operator=(const struct_type& s) {
    Set(s, true);
    return *this;
  }

 protected:
  void Init() {
    memset(static_cast<struct_type*>(this), 0, sizeof(struct_type));
    attached_to_ = nullptr;
    traits::init(this);
  }

  static void Clear(struct_type* s) { traits::clear(s); }

  struct_type* attached_to_ = nullptr;
};

}  // namespace wutil