[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ProgressBar";

let make =
    (
      ~progress: option(float),
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "progress": Js.Undefined.fromOption(progress),
          "color": Js.Undefined.fromOption(color),
          "theme": Js.Undefined.fromOption(theme),
          "style": Js.Undefined.fromOption(style)
        }
      ),
    children
  );
