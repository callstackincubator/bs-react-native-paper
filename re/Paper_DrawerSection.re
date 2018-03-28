[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DrawerSection";

let make = (~title: option(string)=?, ~theme: option(Js.t({..}))=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.({"title": from_opt(title), "theme": from_opt(theme)}),
    children
  );
