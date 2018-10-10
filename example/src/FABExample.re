open BsReactNative;
open Navigation;
open Paper;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.0),
      padding(Pt(4.)),
      backgroundColor(String("#eeeeee")),
    ]);

  let row = style([flex(1.), justifyContent(Center), alignItems(Center)]);

  let fab = style([margin(Pt(8.))]);
};

type state = {visible: bool};

type action =
  | ToggleVisible(bool);

let component = ReasonReact.reducerComponent("FAB example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {visible: false},
  reducer: (action, _state) =>
    switch (action) {
    | ToggleVisible(visible) => ReasonReact.Update({visible: visible})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="FAB example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <View style=Styles.row>
                 <FAB
                   small=true
                   style=Styles.fab
                   onPress={_event => ()}
                   icon={FAB.IconName("add")}
                 />
                 <FAB
                   icon={FAB.IconName("favorite")}
                   style=Styles.fab
                   onPress={_event => ()}
                 />
                 <FAB
                   icon={FAB.IconName("done")}
                   label="Extended FAB"
                   style=Styles.fab
                   onPress={_event => ()}
                 />
                 <FAB
                   icon={FAB.IconName("cancel")}
                   label="Disabled FAB"
                   style=Styles.fab
                   onPress={_event => ()}
                   disabled=true
                 />
                 <Portal>
                   <FAB.Group
                     open_={self.state.visible}
                     onStateChange={
                       _fabState =>
                         self.send(ToggleVisible(!self.state.visible))
                     }
                     icon={
                       self.state.visible ?
                         FAB.IconName("today") : FAB.IconName("add")
                     }
                     actions=[|
                       FAB.Group.fabAction(
                         ~icon=
                           FAB.IconElement(
                             FAB.renderIcon((props: FAB.iconProps) =>
                               <RNIcons.MaterialIcons
                                 name=`_add
                                 size={props.size}
                               />
                             ),
                           ),
                         ~onPress=() => (),
                         (),
                       ),
                       FAB.Group.fabAction(
                         ~icon=FAB.IconName("star"),
                         ~label="Star",
                         ~onPress=() => (),
                         (),
                       ),
                       FAB.Group.fabAction(
                         ~icon=FAB.IconName("email"),
                         ~label="Email",
                         ~onPress=() => (),
                         (),
                       ),
                       FAB.Group.fabAction(
                         ~icon=FAB.IconName("notifications"),
                         ~label="Notifications",
                         ~onPress=() => (),
                         (),
                       ),
                     |]
                   />
                 </Portal>
               </View>
             </View>
         }
    </StackNavigator.Screen>,
};
