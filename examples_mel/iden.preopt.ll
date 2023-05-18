; ModuleID = 'iden.ll'
source_filename = "iden.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [15 x i8] c"Array Size: %d\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @identity([5 x i32]* noundef %a) #0 !dbg !8 {
entry:
  call void @llvm.dbg.value(metadata [5 x i32]* %a, metadata !17, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32 0, metadata !19, metadata !DIExpression()), !dbg !18
  br label %for.cond1.preheader, !dbg !20

for.cond1.preheader:                              ; preds = %entry, %for.inc6
  %indvars.iv7 = phi i64 [ 0, %entry ], [ %indvars.iv.next8, %for.inc6 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv7, metadata !19, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32 0, metadata !22, metadata !DIExpression()), !dbg !18
  br label %for.body3, !dbg !23

for.cond9.preheader:                              ; preds = %for.inc6
  call void @llvm.dbg.value(metadata i32 0, metadata !27, metadata !DIExpression()), !dbg !18
  br label %for.body11, !dbg !28

for.body3:                                        ; preds = %for.cond1.preheader, %for.body3
  %indvars.iv4 = phi i64 [ 0, %for.cond1.preheader ], [ %indvars.iv.next5, %for.body3 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv4, metadata !22, metadata !DIExpression()), !dbg !18
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %a, i64 %indvars.iv7, i64 %indvars.iv4, !dbg !30
  store i32 0, i32* %arrayidx5, align 4, !dbg !33
  %indvars.iv.next5 = add nuw nsw i64 %indvars.iv4, 1, !dbg !34
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next5, metadata !22, metadata !DIExpression()), !dbg !18
  %exitcond6 = icmp ne i64 %indvars.iv.next5, 5, !dbg !35
  br i1 %exitcond6, label %for.body3, label %for.inc6, !dbg !23, !llvm.loop !36

for.inc6:                                         ; preds = %for.body3
  %indvars.iv.next8 = add nuw nsw i64 %indvars.iv7, 1, !dbg !39
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next8, metadata !19, metadata !DIExpression()), !dbg !18
  %exitcond9 = icmp ne i64 %indvars.iv.next8, 5, !dbg !40
  br i1 %exitcond9, label %for.cond1.preheader, label %for.cond9.preheader, !dbg !20, !llvm.loop !41

for.body11:                                       ; preds = %for.cond9.preheader, %for.body11
  %indvars.iv = phi i64 [ 0, %for.cond9.preheader ], [ %indvars.iv.next, %for.body11 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv, metadata !27, metadata !DIExpression()), !dbg !18
  %arrayidx15 = getelementptr inbounds [5 x i32], [5 x i32]* %a, i64 %indvars.iv, i64 %indvars.iv, !dbg !43
  store i32 1, i32* %arrayidx15, align 4, !dbg !46
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1, !dbg !47
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next, metadata !27, metadata !DIExpression()), !dbg !18
  %exitcond = icmp ne i64 %indvars.iv.next, 5, !dbg !48
  br i1 %exitcond, label %for.body11, label %for.end18, !dbg !28, !llvm.loop !49

for.end18:                                        ; preds = %for.body11
  ret void, !dbg !51
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !52 {
entry:
  %a = alloca [5 x [5 x i32]], align 16
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %a, metadata !55, metadata !DIExpression()), !dbg !58
  %arraydecay = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %a, i64 0, i64 0, !dbg !59
  call void @identity([5 x i32]* noundef nonnull %arraydecay), !dbg !60
  call void @llvm.dbg.value(metadata i32 25, metadata !61, metadata !DIExpression()), !dbg !62
  %call = call i32 (i8*, ...) @printf(i8* noundef nonnull dereferenceable(1) getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i64 0, i64 0), i32 noundef 25) #3, !dbg !63
  ret i32 0, !dbg !64
}

declare dso_local i32 @printf(i8* noundef, ...) #2

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #1

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "iden.c", directory: "/home/users/shravank/projects/meliora2/Meliora/examples_mel", checksumkind: CSK_MD5, checksum: "e62aca0071816fd5816ae816b5cceff4")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"uwtable", i32 1}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = !{!"clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)"}
!8 = distinct !DISubprogram(name: "identity", scope: !1, file: !1, line: 7, type: !9, scopeLine: 7, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!9 = !DISubroutineType(types: !10)
!10 = !{null, !11}
!11 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !12, size: 64)
!12 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 160, elements: !14)
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{!15}
!15 = !DISubrange(count: 5)
!16 = !{}
!17 = !DILocalVariable(name: "a", arg: 1, scope: !8, file: !1, line: 7, type: !11)
!18 = !DILocation(line: 0, scope: !8)
!19 = !DILocalVariable(name: "loop_i", scope: !8, file: !1, line: 9, type: !13)
!20 = !DILocation(line: 11, column: 5, scope: !21)
!21 = distinct !DILexicalBlock(scope: !8, file: !1, line: 11, column: 5)
!22 = !DILocalVariable(name: "loop_j", scope: !8, file: !1, line: 9, type: !13)
!23 = !DILocation(line: 12, column: 9, scope: !24)
!24 = distinct !DILexicalBlock(scope: !25, file: !1, line: 12, column: 9)
!25 = distinct !DILexicalBlock(scope: !26, file: !1, line: 11, column: 38)
!26 = distinct !DILexicalBlock(scope: !21, file: !1, line: 11, column: 5)
!27 = !DILocalVariable(name: "loop_k", scope: !8, file: !1, line: 9, type: !13)
!28 = !DILocation(line: 17, column: 5, scope: !29)
!29 = distinct !DILexicalBlock(scope: !8, file: !1, line: 17, column: 5)
!30 = !DILocation(line: 13, column: 13, scope: !31)
!31 = distinct !DILexicalBlock(scope: !32, file: !1, line: 12, column: 42)
!32 = distinct !DILexicalBlock(scope: !24, file: !1, line: 12, column: 9)
!33 = !DILocation(line: 13, column: 30, scope: !31)
!34 = !DILocation(line: 12, column: 39, scope: !32)
!35 = !DILocation(line: 12, column: 29, scope: !32)
!36 = distinct !{!36, !23, !37, !38}
!37 = !DILocation(line: 14, column: 9, scope: !24)
!38 = !{!"llvm.loop.mustprogress"}
!39 = !DILocation(line: 11, column: 35, scope: !26)
!40 = !DILocation(line: 11, column: 25, scope: !26)
!41 = distinct !{!41, !20, !42, !38}
!42 = !DILocation(line: 15, column: 5, scope: !21)
!43 = !DILocation(line: 18, column: 9, scope: !44)
!44 = distinct !DILexicalBlock(scope: !45, file: !1, line: 17, column: 38)
!45 = distinct !DILexicalBlock(scope: !29, file: !1, line: 17, column: 5)
!46 = !DILocation(line: 18, column: 26, scope: !44)
!47 = !DILocation(line: 17, column: 35, scope: !45)
!48 = !DILocation(line: 17, column: 25, scope: !45)
!49 = distinct !{!49, !28, !50, !38}
!50 = !DILocation(line: 19, column: 5, scope: !29)
!51 = !DILocation(line: 20, column: 1, scope: !8)
!52 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 22, type: !53, scopeLine: 22, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!53 = !DISubroutineType(types: !54)
!54 = !{!13}
!55 = !DILocalVariable(name: "a", scope: !52, file: !1, line: 25, type: !56)
!56 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 800, elements: !57)
!57 = !{!15, !15}
!58 = !DILocation(line: 25, column: 9, scope: !52)
!59 = !DILocation(line: 27, column: 14, scope: !52)
!60 = !DILocation(line: 27, column: 5, scope: !52)
!61 = !DILocalVariable(name: "a_size", scope: !52, file: !1, line: 29, type: !13)
!62 = !DILocation(line: 0, scope: !52)
!63 = !DILocation(line: 30, column: 5, scope: !52)
!64 = !DILocation(line: 32, column: 5, scope: !52)
