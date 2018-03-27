[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DrawerSection";

let make = (~title: option(string)=?, ~theme: option(Js.t({..}))=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "title": Js.Undefined.fromOption(title),
          "theme": Js.Undefined.fromOption(theme)
        }
      ),
    children
  );
